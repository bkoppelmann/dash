#include "app/arbiter.hpp"
#include "app/config.hpp"
#include "plugins/launcher_plugin.hpp"
#include "navit/embedded.h"

#include "app/pages/navit.hpp"

NavitPage::NavitPage(Arbiter &arbiter, QWidget *parent)
    : QStackedWidget(parent)
    , Page(arbiter, "Navit", "navit", true, this)
{
}

void NavitPage::init()
{
    //QWidget *widget = new QWidget(this);
    //QVBoxLayout *layout = new QVBoxLayout(widget);
    //layout->setContentsMargins(0, 0, 0, 0);

//  //  QLabel *label = new QLabel("Load Navit Plugin", widget);
//  //  label->setAlignment(Qt::AlignCenter);

    //QHBoxLayout *layout2 = new QHBoxLayout();
    //layout2->setContentsMargins(0, 0, 0, 0);
    //layout2->setSpacing(0);

    //QPushButton *settings_button = new QPushButton(widget);
    //settings_button->setFlat(true);
    //this->arbiter.forge().iconize("settings", settings_button, 24);

    //layout2->addStretch();
    //layout2->addWidget(settings_button);

    //layout->addLayout(layout2);
    //layout->addStretch();
    this->init_navit(); 
    ////layout->addWidget(label);
    //layout->addStretch();

    //this->addWidget(widget);

}

void NavitPage::init_navit()
{
    struct NavitEmbedArgs args;
    
    args.config_path = (char*)"/home/juander/.config/openDsh/navit.xml";
    args.navit_user_dir = (char*)"/home/juander/.navit";
    args.navit_lib_dir = (char*)"/home/juander/code/dash-prefix/usr/local/lib64";
    args.navit_lib_prefix = (char*)"navit/";
    args.log_file = (char*)"/tmp/navit.log";
    start_navit_embedded(&args);
    QWidget *navit_widget = (QWidget*)navit_get_widget();
    this->addWidget(navit_widget);
    navit_widget->show();
}
