#include <loadables.h>
#include <ldns/ldns.h>

/* The builtin function */
int ldnsbash_builtin(list) WORD_LIST *list;
{
	ldns_pkt *p;
	ldns_resolver *res;
	ldns_status s = ldns_resolver_new_frm_file(&res, "/tmp/ldns.conf");
	ldns_rdf *qry = ldns_dname_new_frm_str("whoami.cloudflare");
	ldns_resolver_set_retry(res, 1);

	p = ldns_resolver_query(res, qry, LDNS_RR_TYPE_TXT, LDNS_RR_CLASS_CH, LDNS_RD);

  /* bind to a bash global variable called $LDNSBASH */
	if(p) bind_global_variable("LDNSBASH", ldns_pkt2str(p), 0);

	ldns_rdf_deep_free(ldns_resolver_pop_nameserver(res));
	ldns_resolver_deep_free(res);

	return 0;
}

/* Tell bash what to do when loading the builtin */
int ldnsbash_builtin_load(name) char *name; { return 1; }

/* Tell bash what to do when unloading the builtin */
void ldnsbash_builtin_unload(name) char *name; {}

/* Options for bash */
struct builtin ldnsbash_struct = {
	"ldnsbash",
	ldnsbash_builtin,
	BUILTIN_ENABLED,
	NULL,
	"ldnsbash",
	0
};
