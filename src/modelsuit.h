#ifndef MODELSUIT_H
#define MODELSUIT_H


class ModelSuit
{
    Q_ENUMS(SuitType)
public:
    enum SuitType {
        Build,
        Attack,
        Magic,
        Invalid
    };
    SuitType stringToEnum(QString string);
};
#endif // MODELSUIT_H
