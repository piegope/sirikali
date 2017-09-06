﻿/*
 *
 *  Copyright (c) 2012-2015
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QStringList>
#include <QSystemTrayIcon>
#include <QVector>
#include <QSettings>
#include <QApplication>

#include "volumeinfo.h"
#include "utility.h"
#include "utility2.h"
#include "secrets.h"
#include "mountinfo.h"
#include "lxqt_wallet.h"
#include "keydialog.h"

class QCloseEvent ;
class QAction ;
class QTableWidgetItem ;
class mountinfo ;

namespace Ui {
class sirikali ;
}

class sirikali : public QWidget
{
	Q_OBJECT
public:
	explicit sirikali() ;
	int start( QApplication& ) ;
	~sirikali() ;
private slots:
	void setPluginExecutable( void ) ;
	void setFileManager( void ) ;
	void hideWindow( void ) ;
	void setUpApp( bool,const QString& ) ;
	void start( const QStringList& ) ;
	void autoUpdateCheck( void ) ;
	void gocryptfsProperties( void ) ;
	void cryfsProperties( void ) ;
	void encfsProperties( void ) ;
	void ecryptfsProperties( void ) ;
	void securefsProperties( void ) ;
	void autoMountKeyStorage( void ) ;
	void autoMountKeySource( QAction * ) ;
	void showMountDialogWhenAutoMounting( bool ) ;
	void autoMountWhenAvailable( bool ) ;
	void setDefaultMountPointPrefix( void ) ;
	void autoCheckUpdates( bool ) ;
	void reuseMountPoint( bool ) ;
	void enablePolkitSupport( bool ) ;
	void autoMountFavoritesOnStartUp( bool ) ;
	void unlockVolume( const QStringList& ) ;
	void aboutToShowMenu( void ) ;
	void changeInternalWalletPassWord( void ) ;
	void closeApplication( int = 0,const QString& = QString() ) ;
	void unlockVolume( void ) ;
	void startGUI( void ) ;
	void showMoungDialog( const volumeInfo& ) ;
	void showMoungDialog( const QString&,const QString& = QString() ) ;
	void mount( const volumeInfo&,const QString& = QString(),const QByteArray& = QByteArray() ) ;
	void defaultButton( void ) ;
	void itemClicked( QTableWidgetItem * ) ;
	void pbUpdate( void ) ;
	void createVolume( QAction * = nullptr ) ;
	void slotMount( void ) ;
	void unMountAll( void ) ;
	void unMountAllAndQuit( void ) ;
	void pbUmount( void ) ;
	void slotTrayClicked( QSystemTrayIcon::ActivationReason = QSystemTrayIcon::Trigger ) ;
	void slotCurrentItemChanged( QTableWidgetItem *,QTableWidgetItem * ) ;
	void enableAll( void ) ;
	void slotOpenFolder( void ) ;
	void slotOpenSharedFolder( void ) ;
	void addEntryToTable( const QStringList& ) ;
	void addEntryToTable( const volumeInfo& ) ;
	void autoOpenFolderOnMount( bool ) ;
	void removeEntryFromTable( QString ) ;
	void showFavorites( void ) ;
	void favoriteClicked( QAction * ) ;
	void keyManagerClicked( QAction * ) ;
	void openMountPointPath( const QString& ) ;
	void licenseInfo( void ) ;
	void updateCheck( void ) ;
	void languageMenu( QAction * ac ) ;
	void autoMountFavoritesOnAvailable( QString ) ;
private:
	void mountMultipleVolumes( QVector< std::pair< favorites::entry,QByteArray > > ) ;

	QString resolveFavoriteMountPoint( const QString& ) ;

	QFont getSystemVolumeFont( void ) ;

	bool autoOpenFolderOnMount( void ) ;

	void cliCommand( const QStringList& ) ;
	void updateVolumeList( const QVector< volumeInfo >& ) ;
	void openMountPoint( const QString& ) ;
	void setLocalizationLanguage( bool ) ;
	void dragEnterEvent( QDragEnterEvent * ) ;
	void dropEvent( QDropEvent * ) ;
	void showContextMenu( QTableWidgetItem *,bool ) ;
	void updateList( const volumeInfo& ) ;
	void setUpAppMenu( void ) ;
	void disableAll( void ) ;
	void closeEvent( QCloseEvent * e ) ;
	void setUpFont( void ) ;
	void setUpShortCuts( void ) ;
	void raiseWindow( const QString& = QString() ) ;
	void autoUnlockVolumes( void ) ;

	QVector< std::pair< favorites::entry,QByteArray > >
	autoUnlockVolumes( QVector< std::pair< favorites::entry,QByteArray > >,bool = false ) ;

	Ui::sirikali * m_ui = nullptr ;

	secrets m_secrets ;

	utility2::translator m_translator ;

	QMenu * m_hidden_volume_menu = nullptr ;
	QMenu * m_not_hidden_volume_menu = nullptr ;
	QMenu * m_key_manager_menu = nullptr ;
	QMenu * m_language_menu = nullptr ;
	QMenu * m_autoMountKeyStorage = nullptr ;

	QVector< std::pair< QAction *,const char * > > m_actionPair ;
	QVector< std::pair< QMenu *,const char * > > m_menuPair ;

	QAction * m_unMountAll = nullptr ;
	QAction * m_change_password_action = nullptr ;

	bool m_startHidden ;
	bool m_autoOpenFolderOnMount ;
	bool m_disableEnableAll = false ;

	QString m_sharedFolderPath ;
	QString m_folderOpener ;

	int m_exitStatus = 0 ;

	QSystemTrayIcon m_trayIcon ;

	mountinfo m_mountInfo ;
};

#endif // MAINWINDOW_H
