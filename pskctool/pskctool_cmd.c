/*
  File autogenerated by gengetopt version 2.23
  generated with the following command:
  gengetopt --unamed-opts=FILE --no-handle-version --no-handle-help --input pskctool.ggo --file-name pskctool_cmd 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "pskctool_cmd.h"

const char *gengetopt_args_info_purpose = "Manipulate Portable Symmetric Key Container (PSKC) data.";

const char *gengetopt_args_info_usage = "Usage: " CMDLINE_PARSER_PACKAGE " [OPTION]... [FILE]...";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "This tool allows you to parse, print, validate, sign and verify PSKC data.  The\ninput is provided in FILE or on standard input.";

const char *gengetopt_args_info_help[] = {
  "  -h, --help             Print help and exit",
  "  -V, --version          Print version and exit",
  "      --strict           Fail hard on PSKC parse error  (default=off)",
  "  -d, --debug            Show debug messages on stderr  (default=off)",
  "  -q, --quiet            Quiet operation  (default=off)",
  "  -v, --verbose          Produce more output  (default=off)",
  "\nSelecting one of the following modes is required:",
  "\n Mode: info",
  "  -i, --info             Parse and print human readable summary of PSKC input\n                           (default=off)",
  "\n Mode: validate",
  "  -e, --validate         Validate PSKC input against XML Schema  (default=off)",
  "\n Mode: sign\n  Digitally sign PSKC data",
  "      --sign             Sign PSKC input  (default=off)",
  "      --sign-key=FILE    Private key to sign with",
  "      --sign-crt=FILE    X.509 certificate to sign with",
  "\n Mode: verify\n  Verify digitally signed PSKC data",
  "      --verify           Verify signed PSKC input  (default=off)",
  "      --verify-crt=FILE  Trusted X.509 certificate for verification",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_STRING
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);

static int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error);

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->strict_given = 0 ;
  args_info->debug_given = 0 ;
  args_info->quiet_given = 0 ;
  args_info->verbose_given = 0 ;
  args_info->info_given = 0 ;
  args_info->validate_given = 0 ;
  args_info->sign_given = 0 ;
  args_info->sign_key_given = 0 ;
  args_info->sign_crt_given = 0 ;
  args_info->verify_given = 0 ;
  args_info->verify_crt_given = 0 ;
  args_info->info_mode_counter = 0 ;
  args_info->sign_mode_counter = 0 ;
  args_info->validate_mode_counter = 0 ;
  args_info->verify_mode_counter = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->strict_flag = 0;
  args_info->debug_flag = 0;
  args_info->quiet_flag = 0;
  args_info->verbose_flag = 0;
  args_info->info_flag = 0;
  args_info->validate_flag = 0;
  args_info->sign_flag = 0;
  args_info->sign_key_arg = NULL;
  args_info->sign_key_orig = NULL;
  args_info->sign_crt_arg = NULL;
  args_info->sign_crt_orig = NULL;
  args_info->verify_flag = 0;
  args_info->verify_crt_arg = NULL;
  args_info->verify_crt_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->strict_help = gengetopt_args_info_help[2] ;
  args_info->debug_help = gengetopt_args_info_help[3] ;
  args_info->quiet_help = gengetopt_args_info_help[4] ;
  args_info->verbose_help = gengetopt_args_info_help[5] ;
  args_info->info_help = gengetopt_args_info_help[8] ;
  args_info->validate_help = gengetopt_args_info_help[10] ;
  args_info->sign_help = gengetopt_args_info_help[12] ;
  args_info->sign_key_help = gengetopt_args_info_help[13] ;
  args_info->sign_crt_help = gengetopt_args_info_help[14] ;
  args_info->verify_help = gengetopt_args_info_help[16] ;
  args_info->verify_crt_help = gengetopt_args_info_help[17] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void)
{
	size_t len_purpose = strlen(gengetopt_args_info_purpose);
	size_t len_usage = strlen(gengetopt_args_info_usage);

	if (len_usage > 0) {
		printf("%s\n", gengetopt_args_info_usage);
	}
	if (len_purpose > 0) {
		printf("%s\n", gengetopt_args_info_purpose);
	}

	if (len_usage || len_purpose) {
		printf("\n");
	}

	if (strlen(gengetopt_args_info_description) > 0) {
		printf("%s\n\n", gengetopt_args_info_description);
	}
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);

  args_info->inputs = 0;
  args_info->inputs_num = 0;
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  unsigned int i;
  free_string_field (&(args_info->sign_key_arg));
  free_string_field (&(args_info->sign_key_orig));
  free_string_field (&(args_info->sign_crt_arg));
  free_string_field (&(args_info->sign_crt_orig));
  free_string_field (&(args_info->verify_crt_arg));
  free_string_field (&(args_info->verify_crt_orig));
  
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);

  if (args_info->inputs_num)
    free (args_info->inputs);

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  FIX_UNUSED (values);
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->strict_given)
    write_into_file(outfile, "strict", 0, 0 );
  if (args_info->debug_given)
    write_into_file(outfile, "debug", 0, 0 );
  if (args_info->quiet_given)
    write_into_file(outfile, "quiet", 0, 0 );
  if (args_info->verbose_given)
    write_into_file(outfile, "verbose", 0, 0 );
  if (args_info->info_given)
    write_into_file(outfile, "info", 0, 0 );
  if (args_info->validate_given)
    write_into_file(outfile, "validate", 0, 0 );
  if (args_info->sign_given)
    write_into_file(outfile, "sign", 0, 0 );
  if (args_info->sign_key_given)
    write_into_file(outfile, "sign-key", args_info->sign_key_orig, 0);
  if (args_info->sign_crt_given)
    write_into_file(outfile, "sign-crt", args_info->sign_crt_orig, 0);
  if (args_info->verify_given)
    write_into_file(outfile, "verify", 0, 0 );
  if (args_info->verify_crt_given)
    write_into_file(outfile, "verify-crt", args_info->verify_crt_orig, 0);
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cmdline_parser_required2(args_info, prog_name, 0) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error)
{
  int error_occurred = 0;
  FIX_UNUSED (additional_error);

  /* checks for required options */
  if (args_info->sign_mode_counter && ! args_info->sign_key_given)
    {
      fprintf (stderr, "%s: '--sign-key' option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (args_info->sign_mode_counter && ! args_info->sign_crt_given)
    {
      fprintf (stderr, "%s: '--sign-crt' option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (args_info->verify_mode_counter && ! args_info->verify_crt_given)
    {
      fprintf (stderr, "%s: '--verify-crt' option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  
  /* checks for dependences among options */
  if (args_info->sign_key_given && ! args_info->sign_given)
    {
      fprintf (stderr, "%s: '--sign-key' option depends on option 'sign'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  if (args_info->sign_crt_given && ! args_info->sign_given)
    {
      fprintf (stderr, "%s: '--sign-crt' option depends on option 'sign'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  if (args_info->verify_crt_given && ! args_info->verify_given)
    {
      fprintf (stderr, "%s: '--verify-crt' option depends on option 'verify'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }

  return error_occurred;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  FIX_UNUSED (default_value);
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

	FIX_UNUSED(stop_char);
	
  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
  case ARG_FLAG:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


static int check_modes(
  int given1[], const char *options1[],
                       int given2[], const char *options2[])
{
  int i = 0, j = 0, errors = 0;
  
  while (given1[i] >= 0) {
    if (given1[i]) {
      while (given2[j] >= 0) {
        if (given2[j]) {
          ++errors;
          fprintf(stderr, "%s: option %s conflicts with option %s\n",
                  package_name, options1[i], options2[j]);
        }
        ++j;
      }
    }
    ++i;
  }
  
  return errors;
}

int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  /* TODO: Why is this here? It is not used anywhere. */
  override = params->override;
  FIX_UNUSED(override);

  initialize = params->initialize;
  check_required = params->check_required;

  /* TODO: Why is this here? It is not used anywhere. */
  check_ambiguity = params->check_ambiguity;
  FIX_UNUSED(check_ambiguity);

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "strict",	0, NULL, 0 },
        { "debug",	0, NULL, 'd' },
        { "quiet",	0, NULL, 'q' },
        { "verbose",	0, NULL, 'v' },
        { "info",	0, NULL, 'i' },
        { "validate",	0, NULL, 'e' },
        { "sign",	0, NULL, 0 },
        { "sign-key",	1, NULL, 0 },
        { "sign-crt",	1, NULL, 0 },
        { "verify",	0, NULL, 0 },
        { "verify-crt",	1, NULL, 0 },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVdqvie", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->help_given),
              &(local_args_info.help_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "help", 'h',
              additional_error))
            goto failure;
          cmdline_parser_free (&local_args_info);
          return 0;
        
          break;
        case 'V':	/* Print version and exit.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->version_given),
              &(local_args_info.version_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "version", 'V',
              additional_error))
            goto failure;
          cmdline_parser_free (&local_args_info);
          return 0;
        
          break;
        case 'd':	/* Show debug messages on stderr.  */
        
        
          if (update_arg((void *)&(args_info->debug_flag), 0, &(args_info->debug_given),
              &(local_args_info.debug_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "debug", 'd',
              additional_error))
            goto failure;
        
          break;
        case 'q':	/* Quiet operation.  */
        
        
          if (update_arg((void *)&(args_info->quiet_flag), 0, &(args_info->quiet_given),
              &(local_args_info.quiet_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "quiet", 'q',
              additional_error))
            goto failure;
        
          break;
        case 'v':	/* Produce more output.  */
        
        
          if (update_arg((void *)&(args_info->verbose_flag), 0, &(args_info->verbose_given),
              &(local_args_info.verbose_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "verbose", 'v',
              additional_error))
            goto failure;
        
          break;
        case 'i':	/* Parse and print human readable summary of PSKC input.  */
          args_info->info_mode_counter += 1;
        
        
          if (update_arg((void *)&(args_info->info_flag), 0, &(args_info->info_given),
              &(local_args_info.info_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "info", 'i',
              additional_error))
            goto failure;
        
          break;
        case 'e':	/* Validate PSKC input against XML Schema.  */
          args_info->validate_mode_counter += 1;
        
        
          if (update_arg((void *)&(args_info->validate_flag), 0, &(args_info->validate_given),
              &(local_args_info.validate_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "validate", 'e',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          /* Fail hard on PSKC parse error.  */
          if (strcmp (long_options[option_index].name, "strict") == 0)
          {
          
          
            if (update_arg((void *)&(args_info->strict_flag), 0, &(args_info->strict_given),
                &(local_args_info.strict_given), optarg, 0, 0, ARG_FLAG,
                check_ambiguity, override, 1, 0, "strict", '-',
                additional_error))
              goto failure;
          
          }
          /* Sign PSKC input.  */
          else if (strcmp (long_options[option_index].name, "sign") == 0)
          {
            args_info->sign_mode_counter += 1;
          
          
            if (update_arg((void *)&(args_info->sign_flag), 0, &(args_info->sign_given),
                &(local_args_info.sign_given), optarg, 0, 0, ARG_FLAG,
                check_ambiguity, override, 1, 0, "sign", '-',
                additional_error))
              goto failure;
          
          }
          /* Private key to sign with.  */
          else if (strcmp (long_options[option_index].name, "sign-key") == 0)
          {
            args_info->sign_mode_counter += 1;
          
          
            if (update_arg( (void *)&(args_info->sign_key_arg), 
                 &(args_info->sign_key_orig), &(args_info->sign_key_given),
                &(local_args_info.sign_key_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "sign-key", '-',
                additional_error))
              goto failure;
          
          }
          /* X.509 certificate to sign with.  */
          else if (strcmp (long_options[option_index].name, "sign-crt") == 0)
          {
            args_info->sign_mode_counter += 1;
          
          
            if (update_arg( (void *)&(args_info->sign_crt_arg), 
                 &(args_info->sign_crt_orig), &(args_info->sign_crt_given),
                &(local_args_info.sign_crt_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "sign-crt", '-',
                additional_error))
              goto failure;
          
          }
          /* Verify signed PSKC input.  */
          else if (strcmp (long_options[option_index].name, "verify") == 0)
          {
            args_info->verify_mode_counter += 1;
          
          
            if (update_arg((void *)&(args_info->verify_flag), 0, &(args_info->verify_given),
                &(local_args_info.verify_given), optarg, 0, 0, ARG_FLAG,
                check_ambiguity, override, 1, 0, "verify", '-',
                additional_error))
              goto failure;
          
          }
          /* Trusted X.509 certificate for verification.  */
          else if (strcmp (long_options[option_index].name, "verify-crt") == 0)
          {
            args_info->verify_mode_counter += 1;
          
          
            if (update_arg( (void *)&(args_info->verify_crt_arg), 
                 &(args_info->verify_crt_orig), &(args_info->verify_crt_given),
                &(local_args_info.verify_crt_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "verify-crt", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (args_info->info_mode_counter && args_info->sign_mode_counter) {
    int info_given[] = {args_info->info_given,  -1};
    const char *info_desc[] = {"--info",  0};
    int sign_given[] = {args_info->sign_given, args_info->sign_key_given, args_info->sign_crt_given,  -1};
    const char *sign_desc[] = {"--sign", "--sign-key", "--sign-crt",  0};
    error_occurred += check_modes(info_given, info_desc, sign_given, sign_desc);
  }
  if (args_info->info_mode_counter && args_info->validate_mode_counter) {
    int info_given[] = {args_info->info_given,  -1};
    const char *info_desc[] = {"--info",  0};
    int validate_given[] = {args_info->validate_given,  -1};
    const char *validate_desc[] = {"--validate",  0};
    error_occurred += check_modes(info_given, info_desc, validate_given, validate_desc);
  }
  if (args_info->info_mode_counter && args_info->verify_mode_counter) {
    int info_given[] = {args_info->info_given,  -1};
    const char *info_desc[] = {"--info",  0};
    int verify_given[] = {args_info->verify_given, args_info->verify_crt_given,  -1};
    const char *verify_desc[] = {"--verify", "--verify-crt",  0};
    error_occurred += check_modes(info_given, info_desc, verify_given, verify_desc);
  }
  if (args_info->sign_mode_counter && args_info->validate_mode_counter) {
    int sign_given[] = {args_info->sign_given, args_info->sign_key_given, args_info->sign_crt_given,  -1};
    const char *sign_desc[] = {"--sign", "--sign-key", "--sign-crt",  0};
    int validate_given[] = {args_info->validate_given,  -1};
    const char *validate_desc[] = {"--validate",  0};
    error_occurred += check_modes(sign_given, sign_desc, validate_given, validate_desc);
  }
  if (args_info->sign_mode_counter && args_info->verify_mode_counter) {
    int sign_given[] = {args_info->sign_given, args_info->sign_key_given, args_info->sign_crt_given,  -1};
    const char *sign_desc[] = {"--sign", "--sign-key", "--sign-crt",  0};
    int verify_given[] = {args_info->verify_given, args_info->verify_crt_given,  -1};
    const char *verify_desc[] = {"--verify", "--verify-crt",  0};
    error_occurred += check_modes(sign_given, sign_desc, verify_given, verify_desc);
  }
  if (args_info->validate_mode_counter && args_info->verify_mode_counter) {
    int validate_given[] = {args_info->validate_given,  -1};
    const char *validate_desc[] = {"--validate",  0};
    int verify_given[] = {args_info->verify_given, args_info->verify_crt_given,  -1};
    const char *verify_desc[] = {"--verify", "--verify-crt",  0};
    error_occurred += check_modes(validate_given, validate_desc, verify_given, verify_desc);
  }
  
  if (check_required)
    {
      error_occurred += cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;
      int found_prog_name = 0;
      /* whether program name, i.e., argv[0], is in the remaining args
         (this may happen with some implementations of getopt,
          but surely not with the one included by gengetopt) */

      i = optind;
      while (i < argc)
        if (argv[i++] == argv[0]) {
          found_prog_name = 1;
          break;
        }
      i = 0;

      args_info->inputs_num = argc - optind - found_prog_name;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        if (argv[optind++] != argv[0])
          args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind-1]) ;
    }

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
/* vim: set ft=c noet ts=8 sts=8 sw=8 tw=80 nojs spell : */
