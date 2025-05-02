#define HAVE_CONFIG_H 1
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#define CARES_BUILDING_LIBRARY
#define CARES_STATICLIB
#define WIN32_LEAN_AND_MEAN
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0602
#endif

#define CARES_STATIC 1
#define CARES_THREADS 1

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#endif

#include "ares_private.h"

#include "src/lib/ares_addrinfo2hostent.c"
#include "src/lib/ares_addrinfo_localhost.c"
#include "src/lib/ares_android.c"
#include "src/lib/ares_cancel.c"
#include "src/lib/ares_close_sockets.c"
#include "src/lib/ares_conn.c"
#include "src/lib/ares_cookie.c"
#include "src/lib/ares_data.c"
#include "src/lib/ares_destroy.c"
#include "src/lib/ares_freeaddrinfo.c"
#include "src/lib/ares_free_hostent.c"
#include "src/lib/ares_free_string.c"
#include "src/lib/ares_getaddrinfo.c"
#include "src/lib/ares_getenv.c"
#define next_lookup next_lookup_gethostbyaddr
#define file_lookup file_lookup_gethostbyaddr
#include "src/lib/ares_gethostbyaddr.c"
#undef next_lookup
#undef file_lookup
#define host_query host_query_gethostbyname
#include "src/lib/ares_gethostbyname.c"
#undef host_query
#define lookup_service lookup_service_getnameinfo
#include "src/lib/ares_getnameinfo.c"
#undef lookup_service
#include "src/lib/ares_hosts_file.c"
#include "src/lib/ares_init.c"
#include "src/lib/ares_library_init.c"
#include "src/lib/ares_metrics.c"
#include "src/lib/ares_options.c"
#include "src/lib/ares_parse_into_addrinfo.c"
#include "src/lib/ares_process.c"
#include "src/lib/ares_qcache.c"
#include "src/lib/ares_query.c"
#include "src/lib/ares_search.c"
#include "src/lib/ares_send.c"
#include "src/lib/ares_set_socket_functions.c"
#include "src/lib/ares_socket.c"
#include "src/lib/ares_sortaddrinfo.c"
#include "src/lib/ares_strerror.c"
#include "src/lib/ares_sysconfig.c"
#include "src/lib/ares_sysconfig_files.c"
#include "src/lib/ares_sysconfig_mac.c"
#include "src/lib/ares_sysconfig_win.c"
#include "src/lib/ares_timeout.c"
#include "src/lib/ares_update_servers.c"
#include "src/lib/ares_version.c"
#include "src/lib/inet_net_pton.c"
#include "src/lib/inet_ntop.c"
#include "src/lib/windows_port.c"
#include "src/lib/dsa/ares_array.c"
#include "src/lib/dsa/ares_htable.c"
#include "src/lib/dsa/ares_htable_asvp.c"
#define hash_func   hash_func_dict
#define bucket_key  bucket_key_dict
#define bucket_free bucket_free_dict
#define key_eq      key_eq_dict
#include "src/lib/dsa/ares_htable_dict.c"
#undef hash_func
#undef bucket_key
#undef bucket_free
#undef key_eq
#define hash_func   hash_func_strvp
#define bucket_key  bucket_key_strvp
#define bucket_free bucket_free_strvp
#define key_eq      key_eq_strvp
#include "src/lib/dsa/ares_htable_strvp.c"
#undef hash_func
#undef bucket_key
#undef bucket_free
#undef key_eq
#define hash_func   hash_func_szvp
#define bucket_key  bucket_key_szvp
#define bucket_free bucket_free_szvp
#define key_eq      key_eq_szvp
#include "src/lib/dsa/ares_htable_szvp.c"
#undef hash_func
#undef bucket_key
#undef bucket_free
#undef key_eq
#define hash_func   hash_func_vpstr
#define bucket_key  bucket_key_vpstr
#define bucket_free bucket_free_vpstr
#define key_eq      key_eq_vpstr
#include "src/lib/dsa/ares_htable_vpstr.c"
#undef hash_func
#undef bucket_key
#undef bucket_free
#undef key_eq
#define hash_func   hash_func_vpvp
#define bucket_key  bucket_key_vpvp
#define bucket_free bucket_free_vpvp
#define key_eq      key_eq_vpvp
#include "src/lib/dsa/ares_htable_vpvp.c"
#include "src/lib/dsa/ares_llist.c"
#include "src/lib/dsa/ares_slist.c"
#include "src/lib/event/ares_event_configchg.c"
#include "src/lib/event/ares_event_epoll.c"
#include "src/lib/event/ares_event_kqueue.c"
#include "src/lib/event/ares_event_poll.c"
#pragma push_macro("FD_SETSIZE")
#undef FD_SETSIZE
#include "src/lib/event/ares_event_select.c"
#pragma pop_macro("FD_SETSIZE")
#include "src/lib/event/ares_event_thread.c"
#include "src/lib/event/ares_event_wake_pipe.c"
#include "src/lib/event/ares_event_win32.c"
#include "src/lib/legacy/ares_create_query.c"
#include "src/lib/legacy/ares_expand_name.c"
#include "src/lib/legacy/ares_expand_string.c"
#include "src/lib/legacy/ares_fds.c"
#include "src/lib/legacy/ares_getsock.c"
#include "src/lib/legacy/ares_parse_aaaa_reply.c"
#include "src/lib/legacy/ares_parse_a_reply.c"
#include "src/lib/legacy/ares_parse_caa_reply.c"
#include "src/lib/legacy/ares_parse_mx_reply.c"
#include "src/lib/legacy/ares_parse_naptr_reply.c"
#include "src/lib/legacy/ares_parse_ns_reply.c"
#include "src/lib/legacy/ares_parse_ptr_reply.c"
#include "src/lib/legacy/ares_parse_soa_reply.c"
#include "src/lib/legacy/ares_parse_srv_reply.c"
#include "src/lib/legacy/ares_parse_txt_reply.c"
#include "src/lib/legacy/ares_parse_uri_reply.c"
#include "src/lib/record/ares_dns_mapping.c"
#include "src/lib/record/ares_dns_multistring.c"
#include "src/lib/record/ares_dns_name.c"
#include "src/lib/record/ares_dns_parse.c"
#include "src/lib/record/ares_dns_record.c"
#include "src/lib/record/ares_dns_write.c"
#include "src/lib/str/ares_buf.c"
#include "src/lib/str/ares_str.c"
#include "src/lib/str/ares_strsplit.c"
#include "src/lib/util/ares_iface_ips.c"
#include "src/lib/util/ares_math.c"
#include "src/lib/util/ares_rand.c"
#include "src/lib/util/ares_threads.c"
#include "src/lib/util/ares_timeval.c"
#include "src/lib/util/ares_uri.c"
