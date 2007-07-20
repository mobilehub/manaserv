/*
 *  The Mana World Server
 *  Copyright 2007 The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  The Mana World  is free software; you can redistribute  it and/or modify it
 *  under the terms of the GNU General  Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or any later version.
 *
 *  The Mana  World is  distributed in  the hope  that it  will be  useful, but
 *  WITHOUT ANY WARRANTY; without even  the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 *  more details.
 *
 *  You should  have received a  copy of the  GNU General Public  License along
 *  with The Mana  World; if not, write to the  Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *  $Id$
 */

#include "account-server/characterdata.hpp"

CharacterData::CharacterData(std::string const &name, int id):
    mDatabaseID(id), mAccountID(-1), mName(name), mGender(0), mHairStyle(0),
    mHairColor(0), mLevel(0), mMoney(0), mMapId(0), mPos(0,0)
{
    for (int i = 0; i < NB_BASE_ATTRIBUTES; ++i)
    {
        mBaseAttributes[i] = 0;
    }
}
