#include "app/arbiter.hpp"
#include "app/config.hpp"
#include "plugins/launcher_plugin.hpp"

#include "app/pages/navit.hpp"

NavitPage::NavitPage(Arbiter &arbiter, QWidget *parent)
    : QStackedWidget(parent)
    , Page(arbiter, "Navit", "navit", true, this)
{
}

void NavitPage::init()
{
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel *label = new QLabel("Load Navit Plugin", widget);
    label->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->setContentsMargins(0, 0, 0, 0);
    layout2->setSpacing(0);

    QPushButton *settings_button = new QPushButton(widget);
    settings_button->setFlat(true);
    this->arbiter.forge().iconize("settings", settings_button, 24);

    layout2->addStretch();
    layout2->addWidget(settings_button);

    layout->addLayout(layout2);
    layout->addStretch();
    layout->addWidget(label);
    layout->addStretch();

    this->addWidget(widget);
}
