#include "patterndrafter.h"
#include "ui_patterndrafter.h"

PatternDrafter::PatternDrafter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatternDrafter)
{
    ui->setupUi(this);

    memset(pattern, 0, 8);

    connect(ui->toolButton_00, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_01, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_02, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_03, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_04, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_05, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_06, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_07, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));

    connect(ui->toolButton_10, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_11, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_12, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_13, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_14, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_15, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_16, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_17, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));

    connect(ui->toolButton_20, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_21, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_22, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_23, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_24, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_25, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_26, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_27, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));

    connect(ui->toolButton_30, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_31, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_32, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_33, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_34, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_35, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_36, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_37, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));

    connect(ui->toolButton_40, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_41, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_42, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_43, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_44, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_45, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_46, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_47, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));

    connect(ui->toolButton_50, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_51, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_52, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_53, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_54, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_55, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_56, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_57, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));

    connect(ui->toolButton_60, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_61, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_62, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_63, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_64, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_65, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_66, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_67, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));

    connect(ui->toolButton_70, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_71, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_72, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_73, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_74, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_75, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_76, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
    connect(ui->toolButton_77, SIGNAL(clicked(bool)), this, SLOT(pixelPressed(bool)));
}

PatternDrafter::~PatternDrafter()
{
    delete ui;
}

void PatternDrafter::pixelPressed(bool state) {
         if (QObject::sender() == ui->toolButton_07) { if (state) { pattern[0] |= (1 << 0); } else { pattern[0] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_06) { if (state) { pattern[0] |= (1 << 1); } else { pattern[0] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_05) { if (state) { pattern[0] |= (1 << 2); } else { pattern[0] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_04) { if (state) { pattern[0] |= (1 << 3); } else { pattern[0] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_03) { if (state) { pattern[0] |= (1 << 4); } else { pattern[0] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_02) { if (state) { pattern[0] |= (1 << 5); } else { pattern[0] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_01) { if (state) { pattern[0] |= (1 << 6); } else { pattern[0] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_00) { if (state) { pattern[0] |= (1 << 7); } else { pattern[0] &= ~(1 << 7); } }

    else if (QObject::sender() == ui->toolButton_17) { if (state) { pattern[1] |= (1 << 0); } else { pattern[1] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_16) { if (state) { pattern[1] |= (1 << 1); } else { pattern[1] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_15) { if (state) { pattern[1] |= (1 << 2); } else { pattern[1] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_14) { if (state) { pattern[1] |= (1 << 3); } else { pattern[1] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_13) { if (state) { pattern[1] |= (1 << 4); } else { pattern[1] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_12) { if (state) { pattern[1] |= (1 << 5); } else { pattern[1] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_11) { if (state) { pattern[1] |= (1 << 6); } else { pattern[1] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_10) { if (state) { pattern[1] |= (1 << 7); } else { pattern[1] &= ~(1 << 7); } }

    else if (QObject::sender() == ui->toolButton_27) { if (state) { pattern[2] |= (1 << 0); } else { pattern[2] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_26) { if (state) { pattern[2] |= (1 << 1); } else { pattern[2] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_25) { if (state) { pattern[2] |= (1 << 2); } else { pattern[2] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_24) { if (state) { pattern[2] |= (1 << 3); } else { pattern[2] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_23) { if (state) { pattern[2] |= (1 << 4); } else { pattern[2] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_22) { if (state) { pattern[2] |= (1 << 5); } else { pattern[2] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_21) { if (state) { pattern[2] |= (1 << 6); } else { pattern[2] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_20) { if (state) { pattern[2] |= (1 << 7); } else { pattern[2] &= ~(1 << 7); } }

    else if (QObject::sender() == ui->toolButton_37) { if (state) { pattern[3] |= (1 << 0); } else { pattern[3] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_36) { if (state) { pattern[3] |= (1 << 1); } else { pattern[3] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_35) { if (state) { pattern[3] |= (1 << 2); } else { pattern[3] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_34) { if (state) { pattern[3] |= (1 << 3); } else { pattern[3] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_33) { if (state) { pattern[3] |= (1 << 4); } else { pattern[3] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_32) { if (state) { pattern[3] |= (1 << 5); } else { pattern[3] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_31) { if (state) { pattern[3] |= (1 << 6); } else { pattern[3] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_30) { if (state) { pattern[3] |= (1 << 7); } else { pattern[3] &= ~(1 << 7); } }

    else if (QObject::sender() == ui->toolButton_47) { if (state) { pattern[4] |= (1 << 0); } else { pattern[4] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_46) { if (state) { pattern[4] |= (1 << 1); } else { pattern[4] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_45) { if (state) { pattern[4] |= (1 << 2); } else { pattern[4] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_44) { if (state) { pattern[4] |= (1 << 3); } else { pattern[4] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_43) { if (state) { pattern[4] |= (1 << 4); } else { pattern[4] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_42) { if (state) { pattern[4] |= (1 << 5); } else { pattern[4] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_41) { if (state) { pattern[4] |= (1 << 6); } else { pattern[4] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_40) { if (state) { pattern[4] |= (1 << 7); } else { pattern[4] &= ~(1 << 7); } }

    else if (QObject::sender() == ui->toolButton_57) { if (state) { pattern[5] |= (1 << 0); } else { pattern[5] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_56) { if (state) { pattern[5] |= (1 << 1); } else { pattern[5] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_55) { if (state) { pattern[5] |= (1 << 2); } else { pattern[5] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_54) { if (state) { pattern[5] |= (1 << 3); } else { pattern[5] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_53) { if (state) { pattern[5] |= (1 << 4); } else { pattern[5] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_52) { if (state) { pattern[5] |= (1 << 5); } else { pattern[5] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_51) { if (state) { pattern[5] |= (1 << 6); } else { pattern[5] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_50) { if (state) { pattern[5] |= (1 << 7); } else { pattern[5] &= ~(1 << 7); } }

    else if (QObject::sender() == ui->toolButton_67) { if (state) { pattern[6] |= (1 << 0); } else { pattern[6] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_66) { if (state) { pattern[6] |= (1 << 1); } else { pattern[6] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_65) { if (state) { pattern[6] |= (1 << 2); } else { pattern[6] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_64) { if (state) { pattern[6] |= (1 << 3); } else { pattern[6] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_63) { if (state) { pattern[6] |= (1 << 4); } else { pattern[6] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_62) { if (state) { pattern[6] |= (1 << 5); } else { pattern[6] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_61) { if (state) { pattern[6] |= (1 << 6); } else { pattern[6] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_60) { if (state) { pattern[6] |= (1 << 7); } else { pattern[6] &= ~(1 << 7); } }

    else if (QObject::sender() == ui->toolButton_77) { if (state) { pattern[7] |= (1 << 0); } else { pattern[7] &= ~(1 << 0); } }
    else if (QObject::sender() == ui->toolButton_76) { if (state) { pattern[7] |= (1 << 1); } else { pattern[7] &= ~(1 << 1); } }
    else if (QObject::sender() == ui->toolButton_75) { if (state) { pattern[7] |= (1 << 2); } else { pattern[7] &= ~(1 << 2); } }
    else if (QObject::sender() == ui->toolButton_74) { if (state) { pattern[7] |= (1 << 3); } else { pattern[7] &= ~(1 << 3); } }
    else if (QObject::sender() == ui->toolButton_73) { if (state) { pattern[7] |= (1 << 4); } else { pattern[7] &= ~(1 << 4); } }
    else if (QObject::sender() == ui->toolButton_72) { if (state) { pattern[7] |= (1 << 5); } else { pattern[7] &= ~(1 << 5); } }
    else if (QObject::sender() == ui->toolButton_71) { if (state) { pattern[7] |= (1 << 6); } else { pattern[7] &= ~(1 << 6); } }
    else if (QObject::sender() == ui->toolButton_70) { if (state) { pattern[7] |= (1 << 7); } else { pattern[7] &= ~(1 << 7); } }

    int n = 255;
    char msg[n];
    memset(msg, 0, n);
    sprintf(msg, "{0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X},",
            pattern[0] & 0xFF, pattern[1] & 0xFF, pattern[2] & 0xFF, pattern[3] & 0xFF,
            pattern[4] & 0xFF, pattern[5] & 0xFF, pattern[6] & 0xFF, pattern[7] & 0xFF);
    QString text = QString::fromLocal8Bit(msg);
    ui->textEdit->setText(text);
}
