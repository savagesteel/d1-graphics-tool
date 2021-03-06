#ifndef PALVIEW_H
#define PALVIEW_H

#include <QWidget>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QFileInfo>
#include <QDirIterator>

#include "celview.h"
#include "levelcelview.h"
#include "d1pal.h"
#include "d1trn.h"

#define PALETTE_DEFAULT_WIDTH 192

namespace Ui
{
    class PalView;
}

class PalView : public QWidget
{
    Q_OBJECT

public:
    explicit PalView(QWidget *parent = 0);
    ~PalView();

    void initialize( D1Pal*, D1Trn*, D1Trn*, CelView* );
    void initialize( D1Pal*, D1Trn*, D1Trn*, LevelCelView* );
    void buildPalHits();
    void buildSubtilePalHits();
    void buildTilePalHits();

    void refreshPalettesPathsAndNames();
    void refreshTranslationsPathsAndNames();
    void displayPal();
    void displayTrn();

    void refreshPaletteHitsNames();
    void displayPalHits();
    void displayAllFramesPalHits();
    void displayCurrentFramePalHits();
    void displayCurrentSubtilePalHits();
    void displayCurrentTilePalHits();

    void displayTrnHits();
    void displayAllFramesTrnHits();
    void displayCurrentFrameTrnHits();
    void displayCurrentSubtileTrnHits();
    void displayCurrentTileTrnHits();

private slots:
    void on_palComboBox_currentIndexChanged(const QString &arg1);
    void on_trn1ComboBox_currentIndexChanged(const QString &arg1);
    void on_trn2ComboBox_currentIndexChanged(const QString &arg1);

    void on_palHitsComboBox_currentIndexChanged();

private:
    Ui::PalView *ui;
    bool isCelLevel;
    CelView *celView;
    LevelCelView *levelCelView;

    QGraphicsScene *palScene;
    QGraphicsScene *palHitsScene;

    QGraphicsScene *trn1Scene;
    QGraphicsScene *trn2Scene;
    QGraphicsScene *trn1HitsScene;
    QGraphicsScene *trn2HitsScene;

    D1Pal *pal;
    D1Trn *trn1;
    D1Trn *trn2;

    bool buildingPalComboBox;
    bool buildingTrnComboBox;
    QMap<QString,QString> palettesPaths;
    QMap<QString,QString> translationsPaths;

    // Palette hits are stored with a palette index key and a hit count value
    QMap<quint8,quint32> allFramesPalHits;
    QMap<quint32,QMap<quint8,quint32>> framePalHits;
    QMap<quint32,QMap<quint8,quint32>> tilePalHits;
    QMap<quint32,QMap<quint8,quint32>> subtilePalHits;
};

#endif // PALVIEW_H
