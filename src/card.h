#ifndef CARD_H
#define CARD_H

#include <QObject>
#include "modelsuit.h"

class Card : public QObject
{
    Q_OBJECT
public:
    explicit Card(QString name,
            ModelSuit::SuitType suit,
            qint8 cost,
            QHash<QString, qint8> effect,
            QObject *parent = 0);
    enum {build, attack, magic};

private:
    QString name;
    qint8 cost;
    QHash<QString, qint8> effect;
signals:

public slots:
};

#endif // CARD_H
