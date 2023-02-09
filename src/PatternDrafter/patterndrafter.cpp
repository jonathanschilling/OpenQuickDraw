#include "patterndrafter.h"
#include "ui_patterndrafter.h"

PatternDrafter::PatternDrafter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatternDrafter)
{
    ui->setupUi(this);

    // initial, all pixels cleared
    memset(pattern, 0, 8);

    // array of all tool buttons
    pixelButtons.resize(100);

    pixelButtons[00] = ui->toolButton_00;
    pixelButtons[01] = ui->toolButton_01;
    pixelButtons[02] = ui->toolButton_02;
    pixelButtons[03] = ui->toolButton_03;
    pixelButtons[04] = ui->toolButton_04;
    pixelButtons[05] = ui->toolButton_05;
    pixelButtons[06] = ui->toolButton_06;
    pixelButtons[07] = ui->toolButton_07;

    pixelButtons[10] = ui->toolButton_10;
    pixelButtons[11] = ui->toolButton_11;
    pixelButtons[12] = ui->toolButton_12;
    pixelButtons[13] = ui->toolButton_13;
    pixelButtons[14] = ui->toolButton_14;
    pixelButtons[15] = ui->toolButton_15;
    pixelButtons[16] = ui->toolButton_16;
    pixelButtons[17] = ui->toolButton_17;

    pixelButtons[20] = ui->toolButton_20;
    pixelButtons[21] = ui->toolButton_21;
    pixelButtons[22] = ui->toolButton_22;
    pixelButtons[23] = ui->toolButton_23;
    pixelButtons[24] = ui->toolButton_24;
    pixelButtons[25] = ui->toolButton_25;
    pixelButtons[26] = ui->toolButton_26;
    pixelButtons[27] = ui->toolButton_27;

    pixelButtons[30] = ui->toolButton_30;
    pixelButtons[31] = ui->toolButton_31;
    pixelButtons[32] = ui->toolButton_32;
    pixelButtons[33] = ui->toolButton_33;
    pixelButtons[34] = ui->toolButton_34;
    pixelButtons[35] = ui->toolButton_35;
    pixelButtons[36] = ui->toolButton_36;
    pixelButtons[37] = ui->toolButton_37;

    pixelButtons[40] = ui->toolButton_40;
    pixelButtons[41] = ui->toolButton_41;
    pixelButtons[42] = ui->toolButton_42;
    pixelButtons[43] = ui->toolButton_43;
    pixelButtons[44] = ui->toolButton_44;
    pixelButtons[45] = ui->toolButton_45;
    pixelButtons[46] = ui->toolButton_46;
    pixelButtons[47] = ui->toolButton_47;

    pixelButtons[50] = ui->toolButton_50;
    pixelButtons[51] = ui->toolButton_51;
    pixelButtons[52] = ui->toolButton_52;
    pixelButtons[53] = ui->toolButton_53;
    pixelButtons[54] = ui->toolButton_54;
    pixelButtons[55] = ui->toolButton_55;
    pixelButtons[56] = ui->toolButton_56;
    pixelButtons[57] = ui->toolButton_57;

    pixelButtons[60] = ui->toolButton_60;
    pixelButtons[61] = ui->toolButton_61;
    pixelButtons[62] = ui->toolButton_62;
    pixelButtons[63] = ui->toolButton_63;
    pixelButtons[64] = ui->toolButton_64;
    pixelButtons[65] = ui->toolButton_65;
    pixelButtons[66] = ui->toolButton_66;
    pixelButtons[67] = ui->toolButton_67;

    pixelButtons[70] = ui->toolButton_70;
    pixelButtons[71] = ui->toolButton_71;
    pixelButtons[72] = ui->toolButton_72;
    pixelButtons[73] = ui->toolButton_73;
    pixelButtons[74] = ui->toolButton_74;
    pixelButtons[75] = ui->toolButton_75;
    pixelButtons[76] = ui->toolButton_76;
    pixelButtons[77] = ui->toolButton_77;

    setRowButtons.resize(8);
    setRowButtons[0] = ui->toolButton_set0X;
    setRowButtons[1] = ui->toolButton_set1X;
    setRowButtons[2] = ui->toolButton_set2X;
    setRowButtons[3] = ui->toolButton_set3X;
    setRowButtons[4] = ui->toolButton_set4X;
    setRowButtons[5] = ui->toolButton_set5X;
    setRowButtons[6] = ui->toolButton_set6X;
    setRowButtons[7] = ui->toolButton_set7X;

    clrRowButtons.resize(8);
    clrRowButtons[0] = ui->toolButton_clr0X;
    clrRowButtons[1] = ui->toolButton_clr1X;
    clrRowButtons[2] = ui->toolButton_clr2X;
    clrRowButtons[3] = ui->toolButton_clr3X;
    clrRowButtons[4] = ui->toolButton_clr4X;
    clrRowButtons[5] = ui->toolButton_clr5X;
    clrRowButtons[6] = ui->toolButton_clr6X;
    clrRowButtons[7] = ui->toolButton_clr7X;

    setColButtons.resize(8);
    setColButtons[0] = ui->toolButton_setX0;
    setColButtons[1] = ui->toolButton_setX1;
    setColButtons[2] = ui->toolButton_setX2;
    setColButtons[3] = ui->toolButton_setX3;
    setColButtons[4] = ui->toolButton_setX4;
    setColButtons[5] = ui->toolButton_setX5;
    setColButtons[6] = ui->toolButton_setX6;
    setColButtons[7] = ui->toolButton_setX7;

    clrColButtons.resize(8);
    clrColButtons[0] = ui->toolButton_clrX0;
    clrColButtons[1] = ui->toolButton_clrX1;
    clrColButtons[2] = ui->toolButton_clrX2;
    clrColButtons[3] = ui->toolButton_clrX3;
    clrColButtons[4] = ui->toolButton_clrX4;
    clrColButtons[5] = ui->toolButton_clrX5;
    clrColButtons[6] = ui->toolButton_clrX6;
    clrColButtons[7] = ui->toolButton_clrX7;

    pixelButtonConnections(true);

    connect(ui->toolButton_setAll, SIGNAL(clicked(bool)), this, SLOT(wildcardClicked()));
    connect(ui->toolButton_clrAll, SIGNAL(clicked(bool)), this, SLOT(wildcardClicked()));
    for (int i = 0; i < 8; ++i) {
        connect(setRowButtons[i], SIGNAL(clicked(bool)), this, SLOT(wildcardClicked()));
        connect(clrRowButtons[i], SIGNAL(clicked(bool)), this, SLOT(wildcardClicked()));
        connect(setColButtons[i], SIGNAL(clicked(bool)), this, SLOT(wildcardClicked()));
        connect(clrColButtons[i], SIGNAL(clicked(bool)), this, SLOT(wildcardClicked()));
    }

    connect(ui->spinBox_pixelSpacing, SIGNAL(valueChanged(int)), this, SLOT(pixelSpacingChanged(int)));
    connect(ui->spinBox_zoomFactor, SIGNAL(valueChanged(int)), this, SLOT(zoomFactorChanged(int)));
    connect(ui->toolButton_randomize, SIGNAL(clicked(bool)), this, SLOT(randomizeClicked()));

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    pixelSpacing = ui->spinBox_pixelSpacing->value();
    zoomFactor = ui->spinBox_zoomFactor->value();

    updatePreview();
}

PatternDrafter::~PatternDrafter()
{
    delete ui;
}

void PatternDrafter::pixelButtonConnections(bool enabled) {
    if (enabled) {
        for (int i = 0; i < pixelButtons.size(); ++i) {
            if (pixelButtons[i]) {
                connect(pixelButtons[i], SIGNAL(clicked(bool)), this, SLOT(pixelClicked(bool)));
            }
        }
    } else {
        disconnect(this, SLOT(pixelClicked(bool)));
    }
}

void PatternDrafter::pixelClicked(bool state) {

    bool found = false;

    for (int i = 0; i < pixelButtons.size(); ++i) {
        if (pixelButtons[i] && QObject::sender() == pixelButtons[i]) {

            found = true;

            int row = i / 10;
            int col = i % 10;

            if (state) {
                pattern[row] |= (1 << (7 - col));
            } else {
                pattern[row] &= ~(1 << (7 - col));
            }

            break;
        }
    }

    if (!found) {
        fprintf(stderr, "unknown button\n");
    }

    updateText();
    updatePreview();
}

void PatternDrafter::wildcardClicked() {

    if (QObject::sender() == ui->toolButton_setAll) {
        memset(pattern, 0xFF, 8);
    } else if (QObject::sender() == ui->toolButton_clrAll) {
        memset(pattern, 0x00, 8);
    } else {
        bool found = false;

        for (int i = 0; i < 8; ++i) {
            if (QObject::sender() == setRowButtons[i]) {
                pattern[i] = 0xFF;
                found = true;
                break;
            } else if (QObject::sender() == clrRowButtons[i]) {
                pattern[i] = 0x00;
                found = true;
                break;
            } else if (QObject::sender() == setColButtons[i]) {
                for (int row = 0; row < 8; ++row) {
                    pattern[row] |= (1 << (7 - i));
                }
                found = true;
                break;
            } else if (QObject::sender() == clrColButtons[i]) {
                for (int row = 0; row < 8; ++row) {
                    pattern[row] &= ~(1 << (7 - i));
                }
                found = true;
                break;
            }
        }

        if (!found) {
            fprintf(stderr, "unknown wildcard button\n");
        }
    }

    updatePixelButtons();

    updateText();
    updatePreview();
}

void PatternDrafter::pixelSpacingChanged(int newPixelSpacing) {
    this->pixelSpacing = newPixelSpacing;

    updatePreview();
}

void PatternDrafter::zoomFactorChanged(int newZoomFactor) {
    this->zoomFactor = newZoomFactor;

    updatePreview();
}

void PatternDrafter::randomizeClicked() {

    for (int i = 0; i < 8; ++i) {
        pattern[i] = rand()/((RAND_MAX + 1u)/256);
    }

    updatePixelButtons();

    updateText();
    updatePreview();
}

void PatternDrafter::updateText() {
    int n = 255;
    char msg[n];
    memset(msg, 0, n);
    sprintf(msg, "{0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X},",
            pattern[0] & 0xFF, pattern[1] & 0xFF, pattern[2] & 0xFF, pattern[3] & 0xFF,
            pattern[4] & 0xFF, pattern[5] & 0xFF, pattern[6] & 0xFF, pattern[7] & 0xFF);
    QString text = QString::fromLocal8Bit(msg);
    ui->textEdit->setText(text);
}

void PatternDrafter::updatePixelButtons() {

    pixelButtonConnections(false);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            int buttonIndex = row * 10 + col;
            bool state = pattern[row] & (1 << (7 - col));
            pixelButtons[buttonIndex]->setChecked(state);
        }
    }

    pixelButtonConnections(true);
}

void PatternDrafter::updatePreview() {

    scene->clear();

    int num_x = 8;
    int num_y = 8;

    int width  = num_x * zoomFactor + (num_x - 1)*pixelSpacing;
    int height = num_y * zoomFactor + (num_y - 1)*pixelSpacing;

    QImage image(width, height, QImage::Format_RGB32);

    QRgb black = qRgb(0, 0, 0);
    QRgb white = qRgb(255, 255, 255);

    image.fill(white);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            bool state = pattern[row] & (1 << (7 - col));
            if (state) {

                int offset_x = col * (zoomFactor + pixelSpacing);
                int offset_y = row * (zoomFactor + pixelSpacing);

                for (int x = 0; x  < zoomFactor; ++x) {
                    for (int y = 0; y < zoomFactor; ++y) {
                        image.setPixel(offset_x + x, offset_y + y, black);
                    }
                }

            }
        }
    }

    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    scene->addRect(pixmap.rect());

    ui->graphicsView->show();
}

