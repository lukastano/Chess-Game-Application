#pragma once

#include <QWidget>
#include <QPushButton>

class StartPage : public QWidget {
    Q_OBJECT

public:
    StartPage(QWidget* parent = nullptr);

signals:
    void modeSelected(int mode);

private slots:
    void onModeButtonClicked();

private:
    QPushButton* mode1Button;
    QPushButton* mode2Button;
};
