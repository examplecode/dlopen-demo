/*
 * =====================================================================================
 *
 *       Filename:  plugin.h
 *
 *    Description:  plugin demo with class
 *
 *        Version:  1.0
 *        Created:  01/23/2013 09:18:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
using namespace std;
class Plugin
{
	public:
		virtual string  plugin_name () = 0;
		virtual void do_something() {
			cout << "do nothing " << endl;
		}
};


typedef Plugin * create_t();
typedef void destory_t(Plugin *p);
