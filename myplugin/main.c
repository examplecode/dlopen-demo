/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  demo for load plugin
 *
 *        Version:  1.0
 *        Created:  01/22/2013 10:11:51 PM
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

void (* plugin_fun) ();



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{

	void * plugin ;
	plugin = dlopen("./myplugin.so",RTLD_LAZY);

    const char * err_msg = dlerror();
	if(err_msg) {
		printf("load so error:%s\n",err_msg);
		return -1;
	}
	
	plugin_fun = (void(*) ()) dlsym(plugin,"do_something");
	
	if(err_msg) {
		printf("load so fun:%s\n",err_msg);
		return -1;
	}
	plugin_fun();
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
