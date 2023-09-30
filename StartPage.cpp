#include "StartPage.hpp"

StartPage::StartPage(QWidget* parent) : QWidget(parent) {
    mode1Button = new QPushButton("Mode Regulier", this);
    mode2Button = new QPushButton("Mode Fou et Tour Inverser", this);

    mode1Button->setGeometry(50, 100, 200, 50);
    mode2Button->setGeometry(50, 200, 200, 50);

    connect(mode1Button, &QPushButton::clicked, this, &StartPage::onModeButtonClicked);
    connect(mode2Button, &QPushButton::clicked, this, &StartPage::onModeButtonClicked);
}

void StartPage::onModeButtonClicked() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    int mode = senderButton == mode1Button ? 1 : 2;
    emit modeSelected(mode);
}
