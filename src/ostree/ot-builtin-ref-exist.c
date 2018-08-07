#include "config.h"
#include "ot-main.h"
#include "ot-builtins.h"
#include "ostree.h"
#include "otutil.h"

// Structure for options such as ostree ref-exist --option.
static GOptionEntry options[] = {
    { NULL },
};

gboolean
ostree_builtin_ref_exist (int argc, char **argv, OstreeCommandInvocation *invocation, GCancellable *cancellable, GError **error)
{
    g_autoptr(GOptionContext) context = NULL;
    g_autoptr(OstreeRepo) repo = NULL;
    gboolean ret = FALSE;
    // Creates new command context, ready to be parsed.
    // Input to g_option_context_new shows when running ostree <command> --help
    context = g_option_context_new ("");
    
    // Parses the command context according to the ostree CLI.
    if (!ostree_option_context_parse (context, options, &argc, &argv, invocation, &repo, cancellable, error))
        goto out;
    
    g_print("Hello OSTree!\n");
    ret = TRUE;
    
    out:
     return ret;
}