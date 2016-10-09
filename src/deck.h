#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <QException>

class Deck : public QObject
{
    Q_OBJECT
public:
    explicit Deck(QObject *parent = 0);
    QList<Card::Card> cards;
private:
    QJsonDocument readJson(QString fileName);
    QList<Card::Card> readCards();

signals:

public slots:
};

class InvalidDeckException : public QException
{
public:
    void raise() const { throw *this; }
    InvalidDeckException *clone() const { return new InvalidDeckException(*this); }
};

#endif // DECK_H
