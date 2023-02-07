#ifndef PATTERNDRAFTER_H
#define PATTERNDRAFTER_H

#include <cstring>

#include <QMainWindow>

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
    void pixelPressed(bool state);

private:
    Ui::PatternDrafter *ui;

    uint8_t pattern[8];
};
#endif // PATTERNDRAFTER_H
