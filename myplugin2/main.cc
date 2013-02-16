/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  main.cc
 *
 *        Version:  1.0
 *        Created:  02/16/2013 11:07:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <dlfcn.h>
#include "plugin.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	using std::cout;
	using std::cerr;
	void * plugin = dlopen("./myplugin.so", RTLD_LAZY);
	if (!plugin) {
		cerr << "Cannot load library: " << dlerror() << '\n';
		return 1;
	}

	//reset errors
	dlerror();
    create_t* create_plugin = (create_t*) dlsym(plugin, "createPlugin");
	const char* dlsym_error = dlerror();
    if (dlsym_error) {
		        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
				        return 1;
    }
	
	destory_t * destory_plugin = (destory_t*) dlsym(plugin,"destoryPlugin");

	dlsym_error = dlerror();
    if (dlsym_error) {
		        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
				        return 1;
	}
	Plugin * myplugin =  create_plugin();

	cout << "PluginName is:" << myplugin->plugin_name() << '\n';
	myplugin->do_something();

	destory_plugin(myplugin);
	dlclose(plugin);
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
