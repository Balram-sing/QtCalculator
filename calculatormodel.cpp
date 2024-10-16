#include "calculatormodel.h"
#include <QtMath>
#include <exception>
CalculatorModel::CalculatorModel(QObject *const parent ) noexcept
    : QObject ( parent ),
      mStoredValue( "" ),
      mLeftArg( "" ),
      mRightArg( "" ),
      mOutput( "" ),
      mOperationType( NONE_OPERATION_TYPE )
{

}

CalculatorModel::~CalculatorModel() noexcept=default;

QString CalculatorModel::setOperationType( const QString pType ) noexcept
{

    // Cancel, if Arguments are empty.
    if ( mLeftArg.size( ) < 1 && mRightArg.size( ) < 1 )
        return( mOutput );

    // Cancel, nothing to do.
    if ( mOperationType != NONE_OPERATION_TYPE )
    {

        // SQRT
        if ( mOperationType == DIV_OPERATION_TYPE && pType == "/" && mLeftArg.size( ) > 0 )
        {

            // Convert Left-Argument to number.
            const double arg1_d( mLeftArg.toDouble(  ) );

            // Calculate sqrt.
            const qreal result_ = qSqrt( arg1_d );

            // Set output.
            mOutput = QString::number( result_ );

            // Reset
            onCalculationDone( );

            // Return Output
            return( mOutput );

        } /// SQRT
        else
            return( mOutput );

    } /// Cancel, nothing to do.

    if ( pType == "-" )
        mOperationType = SUB_OPERATION_TYPE;
    else if ( pType == "+" )
        mOperationType = SUM_OPERATION_TYPE;
    else if ( pType == "/" )
        mOperationType = DIV_OPERATION_TYPE;
    else if ( pType == "*" )
        mOperationType = MUL_OPERATION_TYPE;
    else if ( pType == "sqrt" )
    {

        // Cancel, if Argument not set.
        if ( mRightArg.size( ) < 1 )
            return( mOutput );

        // Set Operation-Type
        mOperationType = SQRT_OPERATION_TYPE;

        // Convert Left-Argument to number.
        const double arg1_d( mRightArg.toDouble(  ) );

        // Calculate sqrt.
        const qreal result_ = qSqrt( arg1_d );

        // Set output.
        mOutput = QString::number( result_ );

        // Reset
        onCalculationDone( );

        // Return Output
        return( mOutput );

    } // SQRT

    // Switch Arguments
    mLeftArg = mRightArg; // Copy-Construct
    mRightArg = ""; // Clear/Reset

    // Update Output
    onUpdateOutput( );

    // Return output
    return( mOutput );

}

Q_INVOKABLE QString CalculatorModel::onMR( ) noexcept
{

    // Cancel, if Memory-Item not set.
    if ( mStoredValue.size( ) < 1 )
        return( mOutput );

    // Replace Right-Argument
    mRightArg = mStoredValue; // Copy

    // Update Output-string.
    onUpdateOutput( );

    // Return Output
    return( mOutput );

}

Q_INVOKABLE void CalculatorModel::onMS( ) noexcept
{

    if ( mRightArg.size( ) > 0 )
        mStoredValue = mRightArg;
    else
        mStoredValue.clear( );

}


void CalculatorModel::onUpdateOutput( ) noexcept
{
    // Reset Output-string.
    mOutput = "";

    // Left Argument
    if ( mLeftArg.size( ) > 0 )
        mOutput += mLeftArg;

    // Operation-Type
    if ( mOperationType != NONE_OPERATION_TYPE )
    {

        // Append operation-symbol.
        switch( mOperationType )
        {
        case DIV_OPERATION_TYPE:
        {
            mOutput += " / ";
            break;
        }
        case MUL_OPERATION_TYPE:
        {
            mOutput += " * ";
            break;
        }
        case SQRT_OPERATION_TYPE:
        {
            break;
        }
        case SUB_OPERATION_TYPE:
        {
            mOutput += " - ";
            break;
        }
        default:
        case SUM_OPERATION_TYPE:
        {
            mOutput += " + ";
            break;
        }
        }

    }

    // Right Argument
    if ( mRightArg.size( ) > 0 )
        mOutput += mRightArg;

    // 0
    if ( mOutput.size( ) < 1 )
        mOutput = "0";

}

Q_INVOKABLE QString CalculatorModel::onDot( ) noexcept
{

    // 0
    if ( mRightArg.size( ) < 1 )
    {

        // Set Right Argument
        mRightArg = "0.";

        // Update Output
        onUpdateOutput( );

        // Return Output
        return( mOutput );

    } /// 0

    // Cancel, if Right Argument already contains symbol.
    if ( mRightArg.contains( '.' ) )
        return( mOutput );

    // Append dot-symbol to Right-Argument.
    mRightArg += ".";

    // Update Output
    onUpdateOutput( );

    // Return Output
    return( mOutput );

}

void CalculatorModel::onCalculationDone( ) noexcept
{

    // Reset Left-Argument.
    mLeftArg.clear( );

    // Reset Right-Argument
    mRightArg.clear( );

    // Reset Operation-Type.
    mOperationType = NONE_OPERATION_TYPE;

}

QString CalculatorModel::onKeyboardInput( const QString pValue ) noexcept
{

    // Filter Number Input
    if ( pValue == "0" || pValue == "1" || pValue == "2"
         || pValue == "3" || pValue == "4" || pValue == "5"
         || pValue == "6" || pValue == "7" || pValue == "8"
         || pValue == "9" )
        return( onNumberInput( pValue ) );

    // Return Output
    return( mOutput );

} /// CalculatorModel::onKeyboardInput

QString CalculatorModel::onNumberInput( const QString pVal ) noexcept
{

    // Append
    mRightArg += pVal;

    // Update output
    onUpdateOutput( );

    // Return Output
    return( mOutput );

}

QString CalculatorModel::onRemoveLastNumber( ) noexcept
{

    // Cancel, if nothing to remove
    if ( mRightArg.size( ) == 0 )
        return( mOutput );



    // Remove Last-symbol
    mRightArg.chop( 1 );

    // Update output
    mOutput.chop( 1 );
    //onUpdateOutput( );

    // Return Output
    return( mOutput );

}

QString CalculatorModel::doMath( ) noexcept
{

    // Cancel, if no action required.
    if ( mOperationType == NONE_OPERATION_TYPE || mLeftArg.size( ) < 1 )
        return( mOutput );

    // Convert Left-Argument to number.
    const double arg1_d( mLeftArg.toDouble(  ) );

    // Sqrt
    if ( mRightArg.size( ) < 1 )
    {

        // Calculate sqrt.
        const qreal result_ = qSqrt( arg1_d );

        // Set output.
        mOutput = QString::number( result_ );

        // Reset
        onCalculationDone( );

        // Return Output
        return( mOutput );

    } /// Sqrt

    // Convert Right-Argument to number.
    const double arg2_d( mRightArg.toDouble( ) );

    // Calculate
    switch( mOperationType )
    {
    case SUB_OPERATION_TYPE:
    {


        // Sub
        const auto result_( arg1_d - arg2_d );

        // Set Output
        mOutput = QString::number( result_ );

        // Reset
        onCalculationDone( );

        // Stop
        break;

    }
    case MUL_OPERATION_TYPE:
    {


        // Mult
        const auto result_( arg1_d * arg2_d );

        // Set Output
        mOutput = QString::number( result_ );

        // Reset
        onCalculationDone( );

        // Stop
        break;

    }
    case DIV_OPERATION_TYPE:
    {


        // Div
        const auto result_( arg1_d / arg2_d );

        // Set Output
        mOutput = QString::number( result_ );

        // Reset
        onCalculationDone( );

        // Stop
        break;

    }
    case SUM_OPERATION_TYPE:
    default:
    {

        // Sum
        const auto result_( arg1_d + arg2_d );

        // Set Output
        mOutput = QString::number( result_ );

        // Reset
        onCalculationDone( );

        // Stop
        break;

    }
    }

    // Return Output
    return( mOutput );

}

void CalculatorModel::resetMemory( ) noexcept
{
    // Reset Stored Value
    mStoredValue.clear( );

}

void CalculatorModel::resetLogic( ) noexcept
{



    // Reset Values
    mLeftArg = "";
    mRightArg = "";
    mOutput = "0";
    mOperationType = NONE_OPERATION_TYPE;

}
