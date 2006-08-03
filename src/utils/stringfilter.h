/*
 *  The Mana World Server
 *  Copyright 2004 The Mana World Development Team
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


#ifndef _TMWSERV_SLANGSFILTER_H_
#define _TMWSERV_SLANGSFILTER_H_

#include <list>
#include <string>

class Configuration;

namespace utils
{

/**
 * Used to filter content containing bad words. Like username, character's names, chat, ...
 */
class StringFilter
{
    public:
        /**
         * ctors.
         */
        StringFilter(Configuration *config);

        ~StringFilter();

        /**
         * Load slang list from the config file.
         *
         * @return true is the config is loaded succesfully
         *
         */
        bool
        loadSlangFilterList();

        /**
         * Write slang list to the config file.
         *
         * @return true is the config is loaded succesfully
         *
         */
        void
        writeSlangFilterList();

        /**
        * Useful to filter slangs automatically, by instance.
        * @return true if the sentence is slangs clear.
        */
        bool
        filterContent(const std::string& text);

        /**
         * Tells if an email is valid
         */
        bool
        isEmailValid(const std::string& email);

        /**
         * find double quotes (") in strings.
         * Very useful not to make SQL Queries bqsed on names crash
         * I placed it here cause where you've got " you can have slangs...
         */
        bool
        findDoubleQuotes(const std::string& text);

    private:
        typedef std::list<std::string> Slangs;
        typedef Slangs::iterator SlangIterator;
        Slangs mSlangs;    /**< the formatted Slangs list */
        bool mInitialized;                 /**< Set if the list is loaded */
        Configuration *mConfig;            /**< The config instance */
};

} // ::utils

extern utils::StringFilter *stringFilter;

#endif