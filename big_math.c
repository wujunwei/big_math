/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "calculate.h"
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_big_math.h"

/* If you declare any globals in php_big_math.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(big_math)
*/

/* True global resources - no need for thread safety here */
static int le_big_math;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("big_math.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_big_math_globals, big_math_globals)
    STD_PHP_INI_ENTRY("big_math.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_big_math_globals, big_math_globals)
PHP_INI_END()
*/
/* }}} */


PHP_FUNCTION(b_plus)
{

	zend_bool output;
	char *a = NULL, *b = NULL, *sum = NULL;
	int a_len, b_len, sum_len, args = ZEND_NUM_ARGS();
	if(args > 3)
	{
		WRONG_PARAM_COUNT;
	}

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|b", &a, &a_len, &b, &b_len, &output) == FAILURE) {
		return;
	}
	sum = Plus(a, a_len, b, b_len);
	if(output)
	{
		php_printf("%s + %s = %s\n", a, b, sum);
	}
	RETURN_STRING(sum, 0);
}

PHP_FUNCTION(b_multiply)
{
	zend_bool output;
	char *a = NULL, *b = NULL, *sum = NULL;
	int a_len, b_len, sum_len, args = ZEND_NUM_ARGS();
	if(args > 3)
	{
		WRONG_PARAM_COUNT;
	}
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|b", &a, &a_len, &b, &b_len, &output) == FAILURE) {
		return;
	}
	sum = Multiply(a, a_len, b, b_len);
	if(output)
	{
		php_printf("%s * %s = %s\n", a, b, sum);
	}
	RETURN_STRING(sum, 0);
}

/* {{{ php_big_math_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_big_math_init_globals(zend_big_math_globals *big_math_globals)
{
	big_math_globals->global_value = 0;
	big_math_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(big_math)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(big_math)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(big_math)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(big_math)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(big_math)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "big_math support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ big_math_functions[]
 *
 * Every user visible function must have an entry in big_math_functions[].
 */
const zend_function_entry big_math_functions[] = {
	PHP_FE(b_plus,	NULL)		/* For testing, remove later. */
	PHP_FE(b_multiply, NULL)
	PHP_FE_END	/* Must be the last line in big_math_functions[] */
};
/* }}} */

/* {{{ big_math_module_entry
 */
zend_module_entry big_math_module_entry = {
	STANDARD_MODULE_HEADER,
	"big_math",
	big_math_functions,
	PHP_MINIT(big_math),
	PHP_MSHUTDOWN(big_math),
	PHP_RINIT(big_math),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(big_math),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(big_math),
	PHP_BIG_MATH_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_BIG_MATH
ZEND_GET_MODULE(big_math)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
