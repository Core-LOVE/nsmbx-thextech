#include "frmleveleditor.h"
#include "./ui_frmleveleditor.h"

frmLevelEditor::frmLevelEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::frmLevelEditor)
{
    ui->setupUi(this);
}

frmLevelEditor::~frmLevelEditor()
{
    delete ui;
}

