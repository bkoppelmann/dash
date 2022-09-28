#pragma once

#include <QtWidgets>
#include <QPluginLoader>

#include "app/widgets/selector.hpp"
#include "app/widgets/dialog.hpp"

#include "app/pages/page.hpp"

class Arbiter;

class NavitPage : public QStackedWidget, public Page {
    Q_OBJECT

   public:
    NavitPage(Arbiter &arbiter, QWidget *parent = nullptr);

    void init() override;

   private:
    void init_navit();
};
