#include "deck.h"
#include "card.h"
#include "modelsuit.h"
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QHash>

Deck::Deck(QObject *parent) : QObject(parent)
{
    this->cards = readCards();
}

QJsonDocument Deck::readJson(QString fileName) {
    QString val;
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    return QJsonDocument::fromJson(val.toUtf8());
}

QList<Card::Card> Deck::readCards() {
    QList<Card::Card> cards;
    QJsonDocument jsonDoc = Deck::readJson(cards.json);
    QJsonArray jsonArray = jsonDoc.array();

    foreach (const QJsonValue &value, jsonArray) {
        QJsonObject obj = value.toObject();
        try {
            QString name = obj["name"];
            ModelSuit::SuitType suit = ModelSuit::stringToEnum(obj["suit"]);
            if (suit == ModelSuit::Invalid) {
                throw InvalidDeckException;
            }
            qint8 cost = obj["cost"];

            QHash effects;
            QJsonObject::iterator i;
            for (i = obj.begin(); i != obj.end(); ++i) {
                effects[i.key()] = i.value();
            }

            Card::Card card = Card::Card(name, suit, cost, effects);
            cards.append(card);
        } catch (InvalidDeckException &e) {
            qDebug() << "Invalid Deck: " << e;
        }
    }
    return cards;
}



