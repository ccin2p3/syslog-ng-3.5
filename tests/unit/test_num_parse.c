#include <stdlib.h>

#include "testutils.h"
#include "misc.h"

static void
assert_num_parse (const gchar *str, long expected)
{
  long n;
  gboolean res;

  res = num_parse_int(str, &n);

  assert_gboolean(res, TRUE, "Parsing %s failed", str);
  assert_gint64(n, expected, "Parsing %s failed", str);
}

int
main(int argc, char *argv[])
{
  assert_num_parse("1234", 1234);
  assert_num_parse("+1234", 1234);
  assert_num_parse("-1234", -1234);

  assert_num_parse("1K", 1000);
  assert_num_parse("1k", 1000);
  assert_num_parse("1kB", 1000);
  assert_num_parse("1Kb", 1000);

  assert_num_parse("1m", 1000 * 1000);
  assert_num_parse("1M", 1000 * 1000);

  assert_num_parse("1G", 1000 * 1000 * 1000);
  assert_num_parse("1g", 1000 * 1000 * 1000);

  return 0;
}
