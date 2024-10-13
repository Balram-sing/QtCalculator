#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QString>
#include <QObject>
class CalculatorModel: public QObject
{
    Q_OBJECT



public:

    explicit  CalculatorModel(QObject *const parent = nullptr ) noexcept;
    virtual ~CalculatorModel() noexcept;
    Q_INVOKABLE QString setOperationType( const QString pType ) noexcept;
    Q_INVOKABLE QString onDot( ) noexcept;
    Q_INVOKABLE QString onKeyboardInput( const QString pValue ) noexcept;
    Q_INVOKABLE QString onNumberInput( const QString pNumber ) noexcept;
    Q_INVOKABLE QString onMR( ) noexcept;
    Q_INVOKABLE void onMS( ) noexcept;
    Q_INVOKABLE QString onRemoveLastNumber( ) noexcept;
    Q_INVOKABLE QString doMath( ) noexcept;
    Q_INVOKABLE void resetMemory( ) noexcept;
    Q_INVOKABLE void resetLogic( ) noexcept;
private:
    static const unsigned char NONE_OPERATION_TYPE = 0;
    static const unsigned char SUM_OPERATION_TYPE = 1;
    static const unsigned char SUB_OPERATION_TYPE = 2;
    static const unsigned char DIV_OPERATION_TYPE = 3;
    static const unsigned char MUL_OPERATION_TYPE = 4;
    static const unsigned char SQRT_OPERATION_TYPE = 5;
    QString mStoredValue;

    // First argument.
    QString mLeftArg;

    // Right Argument
    QString mRightArg;

    // Cached Output-String.
    QString mOutput;

    // Operation-Type
    unsigned char mOperationType;
    void onUpdateOutput( ) noexcept;
    void onCalculationDone( ) noexcept;

};

#endif // CALCULATORMODEL_H
