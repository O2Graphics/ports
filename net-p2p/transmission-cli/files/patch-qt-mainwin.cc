--- qt/mainwin.cc.orig	2014-07-21 14:31:59.381934558 +0100
+++ qt/mainwin.cc	2014-07-21 14:35:42.020934743 +0100
@@ -1165,8 +1165,8 @@
   QCheckBox * b = new QCheckBox (tr ("Show &options dialog"));
   b->setChecked (myPrefs.getBool (Prefs::OPTIONS_PROMPT));
   b->setObjectName (SHOW_OPTIONS_CHECKBOX_NAME);
-  auto l = dynamic_cast<QGridLayout*> (d->layout ());
-  if (l == nullptr)
+  auto QGridLayout * l = dynamic_cast<QGridLayout*> (d->layout ());
+  if (l == NULL)
     {
       l = new QGridLayout;
       d->setLayout (l);
@@ -1313,8 +1313,8 @@
   msgBox.setDefaultButton (QMessageBox::Cancel);
   msgBox.setIcon (QMessageBox::Question);
   // hack needed to keep the dialog from being too narrow
-  auto layout = dynamic_cast<QGridLayout*>(msgBox.layout());
-  if (layout == nullptr)
+  auto QGridLayout * layout = dynamic_cast<QGridLayout*>(msgBox.layout());
+  if (layout == NULL)
     {
       layout = new QGridLayout;
       msgBox.setLayout (layout);
