/*
 * =====================================================================================
 *
 *       Filename:  myplugin.cc
 *
 *    Description:  demo
 *
 *        Version:  1.0
 *        Created:  01/23/2013 09:24:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include "plugin.h"

class MyPlugin : public Plugin {
	public:
		string  plugin_name();
		void do_something() ;
};


string  MyPlugin::plugin_name() {
	return "MyPlugin";
}

void MyPlugin::do_something() {
	cout << "MyPlugin Do Something ..." << endl;
}

extern "C" Plugin * createPlugin() {
	return new MyPlugin;
}

extern "C" void destoryPlugin(Plugin * p)
{
	delete p;
}
