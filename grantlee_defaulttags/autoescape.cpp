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

#include "autoescape.h"

#include <QStringList>
#include <QFile>

#include "parser.h"
#include "template.h"
#include "exception.h"

#include "util_p.h"



AutoescapeNodeFactory::AutoescapeNodeFactory()
{

}

Node* AutoescapeNodeFactory::getNode( const QString &tagContent, Parser *p ) const
{
  QStringList expr = tagContent.split( ' ', QString::SkipEmptyParts );

  if ( expr.size() != 2 ) {
    throw Grantlee::Exception( TagSyntaxError, "autoescape takes two arguments." );
  }

  QString strState = expr.at( 1 );
  int state;
  if ( strState == "on" )
    state = AutoescapeNode::On;
  else if ( strState == "off" )
    state = AutoescapeNode::Off;
  else {
    throw Grantlee::Exception( TagSyntaxError, "argument must be 'on' or 'off'" );
  }

  AutoescapeNode *n = new AutoescapeNode( state, p );

  NodeList list = p->parse( n, QStringList() << "endautoescape" );
  p->deleteNextToken();

  n->setList( list );

  return n;
}

AutoescapeNode::AutoescapeNode( int state, QObject *parent )
    : Node( parent ), m_state( state )
{
}


void AutoescapeNode::setList( NodeList list )
{
  m_list = list;
}

QString AutoescapeNode::render( Context *c )
{
  bool old_setting = c->autoescape();
  c->setAutoescape( m_state == On );
  QString output = m_list.render( c );
  c->setAutoescape( old_setting );
  if ( m_state == On ) {
    return Util::markSafe( output );
  }
  return output;
}

