#ifndef PATTERNDRAFTER_H
#define PATTERNDRAFTER_H

#include <cstring>

#include <QDebug>

#include <QMainWindow>
#include <QToolButton>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

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
    void randomizeClicked();

    void zoomFactorPatternChanged(int newZoomFactor);
    void pixelSpacingPatternChanged(int newPixelSpacing);

    void zoomFactorPreviewChanged(int newZoomFactor);

private:
    void updateText();
    void updatePixelButtons();
    void updatePattern();
    void updatePreview();

    void pixelButtonConnections(bool enable);

    Ui::PatternDrafter *ui;

    QVector<QToolButton *> pixelButtons;

    QVector<QToolButton *> setRowButtons;
    QVector<QToolButton *> clrRowButtons;

    QVector<QToolButton *> setColButtons;
    QVector<QToolButton *> clrColButtons;

    uint8_t pattern[8];

    QGraphicsScene *scene_pattern;
    int zoomFactor_pattern;
    int pixelSpacing_pattern;

    QGraphicsScene *scene_preview;
    int zoomFactor_preview;

};
#endif // PATTERNDRAFTER_H
