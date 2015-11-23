/*

Pencil - Traditional Animation Software
Copyright (C) 2005-2007 Patrick Corrieri & Pascal Naidon
Copyright (C) 2013-2015 Matt Chiawen Chang

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation;

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

*/
#ifndef _PREFERENCES_H_
#define _PREFERENCES_H_

#include <QDialog>

class QListWidget;
class QListWidgetItem;
class QStackedWidget;
class PreferenceManager;


class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    PreferencesDialog(QWidget* parent);
    ~PreferencesDialog();

    void init( PreferenceManager* m );
    
    void changePage(QListWidgetItem* current, QListWidgetItem* previous);

Q_SIGNALS:
    void windowOpacityChange(int);
    void curveOpacityChange(int);
    void curveSmoothingChange(int);
    void highResPositionChange(int);
    void antialiasingChange(int);
    void blurryZoomChange(int);
    void backgroundChange(int);
    void shadowsChange(int);
    void toolCursorsChange(int);

    void autosaveChange(int);
    void autosaveNumberChange(int);

    void lengthSizeChange(QString);
    void fontSizeChange(int);
    void frameSizeChange(int);
    void labelChange(int);
    void scrubChange(int);

    void onionMaxOpacityChange(int);
    void onionMinOpacityChange(int);
    void onionPrevFramesNumChange(int);
    void onionNextFramesNumChange(int);

protected:
    void closeEvent( QCloseEvent* ) override;

private:
    void createIcons();
    void makeConnections();

    QListWidget* contentsWidget = nullptr;
    QStackedWidget* pagesWidget = nullptr;

    PreferenceManager* mPrefManager = nullptr;
};


class GeneralPage : public QWidget
{
    Q_OBJECT
public:
    GeneralPage(QWidget* parent = 0);
    void setManager( PreferenceManager* p ) { mManager = p; }

private:
    void antiAliasCheckboxStateChanged( bool b );
    void blurryZoomCheckboxStateChanged( bool b );

    PreferenceManager* mManager = nullptr;
};

class TimelinePage : public QWidget
{
    Q_OBJECT
public:
    TimelinePage(QWidget* parent = 0);
    void setManager( PreferenceManager* p ) { mManager = p; }
private:
    PreferenceManager* mManager = nullptr;
};

class FilesPage : public QWidget
{
    Q_OBJECT

public:
    FilesPage(QWidget* parent = 0);
    void setManager( PreferenceManager* p ) { mManager = p; }
private:
    PreferenceManager* mManager = nullptr;
};


class ToolsPage : public QWidget
{
    Q_OBJECT
public:
    ToolsPage(QWidget* parent = 0);
    void setManager( PreferenceManager* p ) { mManager = p; }
private:
    PreferenceManager* mManager = nullptr;
};

#endif