#ifndef PATTERNDRAFTER_H
#define PATTERNDRAFTER_H

#include <cstring>

#include <QMainWindow>
#include <QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui { class PatternDrafter; }
QT_END_NAMESPACE

class PatternDrafter : public QMainWindow
{
    Q_OBJECT

public:
    PatternDrafter(QWidget *parent = nullptr);
    ~PatternDrafter();

public slots:
    void pixelClicked(bool state);
    void wildcardClicked();

private:
    void updateText();
    void updatePixelButtons();

    void pixelButtonConnections(bool enabled);

    Ui::PatternDrafter *ui;

    QVector<QToolButton *> pixelButtons;

    QVector<QToolButton *> setRowButtons;
    QVector<QToolButton *> clrRowButtons;

    QVector<QToolButton *> setColButtons;
    QVector<QToolButton *> clrColButtons;

    uint8_t pattern[8];
};
#endif // PATTERNDRAFTER_H
