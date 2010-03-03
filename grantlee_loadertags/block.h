/*
  This file is part of the Grantlee template system.

  Copyright (c) 2009,2010 Stephen Kelly <steveire@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either version
  2 of the Licence, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include "node.h"

namespace Grantlee
{
class Parser;
}

using namespace Grantlee;

class BlockNodeFactory : public AbstractNodeFactory
{
  Q_OBJECT
public:
  explicit BlockNodeFactory( QObject *parent = 0 );

  Node* getNode( const QString &tagContent, Parser *p ) const;

};

class BlockNode : public Node
{
  Q_OBJECT
  Q_PROPERTY( Grantlee::SafeString super READ getSuper )
public:
  BlockNode( const QString &blockName, QObject *parent = 0 );
  ~BlockNode();

  void setNodeList( NodeList list );

  QString blockName();

  QString render( Context *c );

  BlockNode* takeNodeParent();

  QString name();

  void setNodeParent( BlockNode * );

  void addParent( NodeList );

  NodeList nodeList();

// slots
  /**
  Returns the block overridden by this one rendered in context.
  */
  SafeString getSuper() const;

private:
  QString m_name;
  NodeList m_list;
  Context *m_context;
  BlockNode *m_nodeParent;

};

#endif

