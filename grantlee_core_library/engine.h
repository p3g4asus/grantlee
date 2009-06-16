/*
  This file is part of the Grantlee template system.

  Copyright (c) 2009 Stephen Kelly <steveire@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 3 only, as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License version 3 for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef ENGINE_H
#define ENGINE_H

#include "template.h"
#include "mutabletemplate.h"

namespace Grantlee
{

class AbstractTemplateLoader : public QObject
{
  Q_OBJECT
public:
  AbstractTemplateLoader( QObject* parent = 0 );
  virtual ~AbstractTemplateLoader();

  virtual MutableTemplate* loadMutableByName( const QString &name ) const = 0;
  virtual Template* loadByName( const QString &name ) const = 0;

};

class FileSystemTemplateLoader : public AbstractTemplateLoader
{
  Q_OBJECT
public:
  FileSystemTemplateLoader( QObject* parent = 0 );
  MutableTemplate* loadMutableByName( const QString &name ) const;
  Template* loadByName( const QString &name ) const;

  void setTheme( const QString &themeName );
  QString themeName() const;
  void setTemplateDirs( const QStringList &dirs );

private:
  QString m_themeName;
  QStringList m_templateDirs;
};

class InMemoryTemplateLoader : public AbstractTemplateLoader
{
  Q_OBJECT
public:
  InMemoryTemplateLoader( QObject* parent = 0 );
  MutableTemplate* loadMutableByName( const QString &name ) const;
  Template* loadByName( const QString &name ) const;

  void setTemplate( const QString &name, const QString &content );

private:
  QHash<QString, QString> m_namedTemplates;
};

class EnginePrivate;

class GRANTLEE_EXPORT Engine
{
public:
  static Engine* instance();

  ~Engine();

  QList<AbstractTemplateLoader*> templateLoaders();

  void addTemplateLoader( AbstractTemplateLoader *loader );

  void setPluginDirs( const QStringList &dirs );

  QStringList pluginDirs();

  Template* loadByName( const QString &name, QObject *parent ) const;

  Template* newTemplate( const QString &content, QObject *parent = 0 );

  MutableTemplate* loadMutableByName( const QString &name, QObject *parent ) const;

  MutableTemplate* newMutableTemplate( const QString &content, QObject *parent = 0 );

  QStringList defaultLibraries() const;
  void setDefaultLibraries( const QStringList &list );
  void addDefaultLibrary( const QString &libName );
  void removeDefaultLibrary( const QString &libName );

private:
  Engine();

  Q_DECLARE_PRIVATE( Engine );
  EnginePrivate *d_ptr;

  static Engine* m_instance;
};

}

#endif

