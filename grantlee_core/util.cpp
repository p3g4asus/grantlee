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

#include "util_p.h"

Util::Util()
{

}

QString Util::unescapeStringLiteral( const QString &input )
{
  return input.mid( 1, input.size() - 2 )
         .replace( "\\\'", QChar( '\'' ) )
         .replace( "\\\"", QChar( '"' ) )
         .replace( "\\\\", QChar( '\\' ) );
}

bool Util::variantIsTrue( const QVariant &variant )
{

  if ( !variant.isValid() )
    return false;
  switch ( variant.userType() ) {
  case QVariant::Bool: {
    return variant.toBool();
  }
  case QVariant::Int: {
    return ( variant.toInt() > 0 );
  }
  case QVariant::Double: {
    return ( variant.toDouble() > 0 );
  }
  case QMetaType::QObjectStar: {
    QObject *obj = variant.value<QObject *>();
    if ( !obj )
      return false;

    if ( obj->property( "__true__" ).isValid() ) {
      return obj->property( "__true__" ).toBool();
    }
    return true;
  }
  case QVariant::List: {
    return ( variant.toList().size() > 0 );
  }
  case QVariant::Map: {
    return ( variant.toMap().size() > 0 );
  }
  }

  Grantlee::SafeString str = getSafeString( variant );
  return !str->isEmpty();
}

QVariantList Util::variantToList( const QVariant &var )
{

  if ( !var.isValid() )
    return QVariantList();

  if ( var.type() == QVariant::List ) {
    return var.toList();
  }

  if ( var.type() == QVariant::Hash ) {
    QVariantHash varHash = var.toHash();
    QVariantList list;

    QVariantHash::const_iterator it = varHash.constBegin();
    for ( ; it != varHash.constEnd(); ++it )
      list << it.key();

    return list;
  }

  if ( var.userType() == QMetaType::QObjectStar ) {
    QObject *obj = var.value<QObject*>();
    if ( obj->property( "__list__" ).isValid() ) {
      return obj->property( "__list__" ).toList();
    }
  } else {
    return QVariantList() << var;
  }
  return QVariantList();
}

Grantlee::SafeString Util::conditionalEscape( const Grantlee::SafeString &input )
{
  Grantlee::SafeString temp = input;
  if ( !temp.isSafe() )
    return escape( temp );
  return temp;
}

Grantlee::SafeString Util::markSafe( const Grantlee::SafeString &input )
{
  Grantlee::SafeString sret = input;
  sret.setSafety( Grantlee::SafeString::IsSafe );
  return sret;
}

Grantlee::SafeString Util::markForEscaping( const Grantlee::SafeString &input )
{
  Grantlee::SafeString temp = input;
  if ( input.isSafe() || input.needsEscape() )
    return input;

  temp.setNeedsEscape( true );
  return temp;
}

// This should probably take a QString instead.
Grantlee::SafeString Util::escape( const Grantlee::SafeString &input )
{
  QString temp = input;
  temp.replace( '&', "&amp;" );
  temp.replace( '<', "&lt;" );
  temp.replace( '>', "&gt;" );
  temp.replace( '\'', "&#39;" );
  return temp;

}

Grantlee::SafeString Util::getSafeString( const QVariant &input )
{
  if ( input.userType() == qMetaTypeId<Grantlee::SafeString>() ) {
    return input.value<Grantlee::SafeString>();
  } else {
    return input.toString();
  }
}

bool Util::isSafeString( const QVariant &input )
{
  int type = input.userType();
  return (( type == qMetaTypeId<Grantlee::SafeString>() )
          || type == QVariant::String );
}

bool Util::supportedOutputType( const QVariant &input )
{
  QList<int> primitives;
  primitives << qMetaTypeId<Grantlee::SafeString>()
             << QVariant::Bool
             << QVariant::Int
             << QVariant::Double
             << QVariant::DateTime;
  return primitives.contains( input.userType() );
}


bool Util::equals( const QVariant &lhs, const QVariant &rhs )
{

  // QVariant doesn't use operator== to compare its held data, so we do it manually instead for SafeString.
  bool equal = false;
  if ( lhs.userType() == qMetaTypeId<Grantlee::SafeString>() ) {
    if ( rhs.userType() == qMetaTypeId<Grantlee::SafeString>() ) {
      equal = ( lhs.value<Grantlee::SafeString>() == rhs.value<Grantlee::SafeString>() );
    } else if ( rhs.userType() == QVariant::String ) {
      equal = ( lhs.value<Grantlee::SafeString>() == rhs.toString() );
    }
  } else if ( rhs.userType() == qMetaTypeId<Grantlee::SafeString>() && lhs.userType() == QVariant::String ) {
    equal = ( rhs.value<Grantlee::SafeString>() == lhs.toString() );
  }  else {
    equal = (( lhs == rhs ) && ( lhs.userType() == rhs.userType() ) );
  }
  return equal;
}

Grantlee::SafeString Util::toString( const QVariantList &list )
{
  QString output( '[' );
  QVariantList::const_iterator it = list.constBegin();
  const QVariantList::const_iterator end = list.constEnd();
  while ( it != end ) {
    QVariant item = *it;
    if ( isSafeString( item ) ) {
      output.append( "u\'" );
      output.append( getSafeString( item ) );
      output.append( '\'' );
      if (( it + 1 ) != end )
        output.append( ", " );
    }
    if ( item.type() == QVariant::List ) {
      output.append( toString( item.toList() ) );
      output.append( ", " );
    }
    ++it;
  }

  return output.append( ']' );
}

