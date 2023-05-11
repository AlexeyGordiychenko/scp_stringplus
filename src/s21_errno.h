#ifndef S21_ERRNO_H
#define S21_ERRNO_H

#ifdef __linux__

#define  S21_EPERM     1  /* Operation not permitted */
#define  S21_ENOENT    2  /* No such file or directory */
#define  S21_ESRCH     3  /* No such process */
#define  S21_EINTR     4  /* Interrupted system call */
#define  S21_EIO       5  /* I/O error */
#define  S21_ENXIO     6  /* No such device or address */
#define  S21_E2BIG     7  /* Argument list too long */
#define  S21_ENOEXEC   8  /* Exec format error */
#define  S21_EBADF     9  /* Bad file number */
#define  S21_ECHILD    10  /* No child processes */
#define  S21_EAGAIN    11  /* Try again */
#define  S21_ENOMEM    12  /* Out of memory */
#define  S21_EACCES    13  /* Permission denied */
#define  S21_EFAULT    14  /* Bad address */
#define  S21_ENOTBLK   15  /* Block device required */
#define  S21_EBUSY     16  /* Device or resource busy */
#define  S21_EEXIST    17  /* File exists */
#define  S21_EXDEV     18  /* Cross-device link */
#define  S21_ENODEV    19  /* No such device */
#define  S21_ENOTDIR   20  /* Not a directory */
#define  S21_EISDIR    21  /* Is a directory */
#define  S21_EINVAL    22  /* Invalid argument */
#define  S21_ENFILE    23  /* File table overflow */
#define  S21_EMFILE    24  /* Too many open files */
#define  S21_ENOTTY    25  /* Not a typewriter */
#define  S21_ETXTBSY   26  /* Text file busy */
#define  S21_EFBIG     27  /* File too large */
#define  S21_ENOSPC    28  /* No space left on device */
#define  S21_ESPIPE    29  /* Illegal seek */
#define  S21_EROFS     30  /* Read-only file system */
#define  S21_EMLINK    31  /* Too many links */
#define  S21_EPIPE     32  /* Broken pipe */
#define  S21_EDOM      33  /* Math argument out of domain of func */
#define  S21_ERANGE    34  /* Math result not representable */
#define  S21_EDEADLK   35  /* Resource deadlock would occur */
#define  S21_ENAMETOOLONG  36  /* File name too long */
#define  S21_ENOLCK    37  /* No record locks available */
#define  S21_ENOSYS    38  /* Invalid system call number */
#define  S21_ENOTEMPTY 39  /* Directory not empty */
#define  S21_ELOOP     40  /* Too many symbolic links encountered */
#define  S21_EWOULDBLOCK  EAGAIN  /* Operation would block */
#define  S21_ENOMSG    42  /* No message of desired type */
#define  S21_EIDRM     43  /* Identifier removed */
#define  S21_ECHRNG    44  /* Channel number out of range */
#define  S21_EL2NSYNC  45  /* Level 2 not synchronized */
#define  S21_EL3HLT    46  /* Level 3 halted */
#define  S21_EL3RST    47  /* Level 3 reset */
#define  S21_ELNRNG    48  /* Link number out of range */
#define  S21_EUNATCH   49  /* Protocol driver not attached */
#define  S21_ENOCSI    50  /* No CSI structure available */
#define  S21_EL2HLT    51  /* Level 2 halted */
#define  S21_EBADE     52  /* Invalid exchange */
#define  S21_EBADR     53  /* Invalid request descriptor */
#define  S21_EXFULL    54  /* Exchange full */
#define  S21_ENOANO    55  /* No anode */
#define  S21_EBADRQC   56  /* Invalid request code */
#define  S21_EBADSLT   57  /* Invalid slot */
#define  S21_EDEADLOCK  EDEADLK
#define  S21_EBFONT    59  /* Bad font file format */
#define  S21_ENOSTR    60  /* Device not a stream */
#define  S21_ENODATA   61  /* No data available */
#define  S21_ETIME     62  /* Timer expired */
#define  S21_ENOSR     63  /* Out of streams resources */
#define  S21_ENONET    64  /* Machine is not on the network */
#define  S21_ENOPKG    65  /* Package not installed */
#define  S21_EREMOTE   66  /* Object is remote */
#define  S21_ENOLINK   67  /* Link has been severed */
#define  S21_EADV      68  /* Advertise error */
#define  S21_ESRMNT    69  /* Srmount error */
#define  S21_ECOMM     70  /* Communication error on send */
#define  S21_EPROTO    71  /* Protocol error */
#define  S21_EMULTIHOP 72  /* Multihop attempted */
#define  S21_EDOTDOT   73  /* RFS specific error */
#define  S21_EBADMSG   74  /* Not a data message */
#define  S21_EOVERFLOW 75  /* Value too large for defined data type */
#define  S21_ENOTUNIQ  76  /* Name not unique on network */
#define  S21_EBADFD    77  /* File descriptor in bad state */
#define  S21_EREMCHG   78  /* Remote address changed */
#define  S21_ELIBACC   79  /* Can not access a needed shared library */
#define  S21_ELIBBAD   80  /* Accessing a corrupted shared library */
#define  S21_ELIBSCN   81  /* .lib section in a.out corrupted */
#define  S21_ELIBMAX   82  /* Attempting to link in too many shared libraries */
#define  S21_ELIBEXEC  83  /* Cannot exec a shared library directly */
#define  S21_EILSEQ    84  /* Illegal byte sequence */
#define  S21_ERESTART  85  /* Interrupted system call should be restarted */
#define  S21_ESTRPIPE  86  /* Streams pipe error */
#define  S21_EUSERS    87  /* Too many users */
#define  S21_ENOTSOCK  88  /* Socket operation on non-socket */
#define  S21_EDESTADDRREQ  89  /* Destination address required */
#define  S21_EMSGSIZE  90  /* Message too long */
#define  S21_EPROTOTYPE  91  /* Protocol wrong type for socket */
#define  S21_ENOPROTOOPT 92  /* Protocol not available */
#define  S21_EPROTONOSUPPORT  93  /* Protocol not supported */
#define  S21_ESOCKTNOSUPPORT  94  /* Socket type not supported */
#define  S21_EOPNOTSUPP  95  /* Operation not supported on transport endpoint */
#define  S21_EPFNOSUPPORT  96  /* Protocol family not supported */
#define  S21_EAFNOSUPPORT  97  /* Address family not supported by protocol */
#define  S21_EADDRINUSE  98  /* Address already in use */
#define  S21_EADDRNOTAVAIL  99  /* Cannot assign requested address */
#define  S21_ENETDOWN  100  /* Network is down */
#define  S21_ENETUNREACH  101  /* Network is unreachable */
#define  S21_ENETRESET  102  /* Network dropped connection because of reset */
#define  S21_ECONNABORTED  103  /* Software caused connection abort */
#define  S21_ECONNRESET  104  /* Connection reset by peer */
#define  S21_ENOBUFS    105  /* No buffer space available */
#define  S21_EISCONN    106  /* Transport endpoint is already connected */
#define  S21_ENOTCONN  107  /* Transport endpoint is not connected */
#define  S21_ESHUTDOWN  108  /* Cannot send after transport endpoint shutdown */
#define  S21_ETOOMANYREFS  109  /* Too many references: cannot splice */
#define  S21_ETIMEDOUT  110  /* Connection timed out */
#define  S21_ECONNREFUSED  111  /* Connection refused */
#define  S21_EHOSTDOWN  112  /* Host is down */
#define  S21_EHOSTUNREACH  113  /* No route to host */
#define  S21_EALREADY  114  /* Operation already in progress */
#define  S21_EINPROGRESS  115  /* Operation now in progress */
#define  S21_ESTALE    116  /* Stale file handle */
#define  S21_EUCLEAN    117  /* Structure needs cleaning */
#define  S21_ENOTNAM    118  /* Not a XENIX named type file */
#define  S21_ENAVAIL    119  /* No XENIX semaphores available */
#define  S21_EISNAM    120  /* Is a named type file */
#define  S21_EREMOTEIO  121  /* Remote I/O error */
#define  S21_EDQUOT    122  /* Quota exceeded */
#define  S21_ENOMEDIUM  123  /* No medium found */
#define  S21_EMEDIUMTYPE  124  /* Wrong medium type */
#define  S21_ECANCELED  125  /* Operation Canceled */
#define  S21_ENOKEY    126  /* Required key not available */
#define  S21_EKEYEXPIRED  127  /* Key has expired */
#define  S21_EKEYREVOKED  128  /* Key has been revoked */
#define  S21_EKEYREJECTED  129  /* Key was rejected by service */
/* for robust mutexes */
#define  S21_EOWNERDEAD  130  /* Owner died */
#define  S21_ENOTRECOVERABLE  131  /* State not recoverable */
#define S21_ERFKILL    132  /* Operation not possible due to RF-kill */
#define S21_EHWPOISON  133  /* Memory page has hardware error */

#endif /* __linux__ */

#ifdef __APPLE__

#define S21_EPERM           1               /* Operation not permitted */
#define S21_ENOENT          2               /* No such file or directory */
#define S21_ESRCH           3               /* No such process */
#define S21_EINTR           4               /* Interrupted system call */
#define S21_EIO             5               /* Input/output error */
#define S21_ENXIO           6               /* Device not configured */
#define S21_E2BIG           7               /* Argument list too long */
#define S21_ENOEXEC         8               /* Exec format error */
#define S21_EBADF           9               /* Bad file descriptor */
#define S21_ECHILD          10              /* No child processes */
#define S21_EDEADLK         11              /* Resource deadlock avoided */
                                        /* 11 was EAGAIN */
#define S21_ENOMEM          12              /* Cannot allocate memory */
#define S21_EACCES          13              /* Permission denied */
#define S21_EFAULT          14              /* Bad address */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_ENOTBLK         15              /* Block device required */
#endif
#define S21_EBUSY           16              /* Device / Resource busy */
#define S21_EEXIST          17              /* File exists */
#define S21_EXDEV           18              /* Cross-device link */
#define S21_ENODEV          19              /* Operation not supported by device */
#define S21_ENOTDIR         20              /* Not a directory */
#define S21_EISDIR          21              /* Is a directory */
#define S21_EINVAL          22              /* Invalid argument */
#define S21_ENFILE          23              /* Too many open files in system */
#define S21_EMFILE          24              /* Too many open files */
#define S21_ENOTTY          25              /* Inappropriate ioctl for device */
#define S21_ETXTBSY         26              /* Text file busy */
#define S21_EFBIG           27              /* File too large */
#define S21_ENOSPC          28              /* No space left on device */
#define S21_ESPIPE          29              /* Illegal seek */
#define S21_EROFS           30              /* Read-only file system */
#define S21_EMLINK          31              /* Too many links */
#define S21_EPIPE           32              /* Broken pipe */

/* math software */
#define S21_EDOM            33              /* Numerical argument out of domain */
#define S21_ERANGE          34              /* Result too large */

/* non-blocking and interrupt i/o */
#define S21_EAGAIN          35              /* Resource temporarily unavailable */
#define S21_EWOULDBLOCK     EAGAIN          /* Operation would block */
#define S21_EINPROGRESS     36              /* Operation now in progress */
#define S21_EALREADY        37              /* Operation already in progress */

/* ipc/network software -- argument errors */
#define S21_ENOTSOCK        38              /* Socket operation on non-socket */
#define S21_EDESTADDRREQ    39              /* Destination address required */
#define S21_EMSGSIZE        40              /* Message too long */
#define S21_EPROTOTYPE      41              /* Protocol wrong type for socket */
#define S21_ENOPROTOOPT     42              /* Protocol not available */
#define S21_EPROTONOSUPPORT 43              /* Protocol not supported */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_ESOCKTNOSUPPORT 44              /* Socket type not supported */
#endif
#define S21_ENOTSUP         45              /* Operation not supported */

#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_EPFNOSUPPORT    46              /* Protocol family not supported */
#endif
#define S21_EAFNOSUPPORT    47              /* Address family not supported by protocol family */
#define S21_EADDRINUSE      48              /* Address already in use */
#define S21_EADDRNOTAVAIL   49              /* Can't assign requested address */

/* ipc/network software -- operational errors */
#define S21_ENETDOWN        50              /* Network is down */
#define S21_ENETUNREACH     51              /* Network is unreachable */
#define S21_ENETRESET       52              /* Network dropped connection on reset */
#define S21_ECONNABORTED    53              /* Software caused connection abort */
#define S21_ECONNRESET      54              /* Connection reset by peer */
#define S21_ENOBUFS         55              /* No buffer space available */
#define S21_EISCONN         56              /* Socket is already connected */
#define S21_ENOTCONN        57              /* Socket is not connected */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_ESHUTDOWN       58              /* Can't send after socket shutdown */
#define S21_ETOOMANYREFS    59              /* Too many references: can't splice */
#endif
#define S21_ETIMEDOUT       60              /* Operation timed out */
#define S21_ECONNREFUSED    61              /* Connection refused */

#define S21_ELOOP           62              /* Too many levels of symbolic links */
#define S21_ENAMETOOLONG    63              /* File name too long */

/* should be rearranged */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_EHOSTDOWN       64              /* Host is down */
#endif
#define S21_EHOSTUNREACH    65              /* No route to host */
#define S21_ENOTEMPTY       66              /* Directory not empty */

/* quotas & mush */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_EPROCLIM        67              /* Too many processes */
#define S21_EUSERS          68              /* Too many users */
#endif
#define S21_EDQUOT          69              /* Disc quota exceeded */

/* Network File System */
#define S21_ESTALE          70              /* Stale NFS file handle */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_EREMOTE         71              /* Too many levels of remote in path */
#define S21_EBADRPC         72              /* RPC struct is bad */
#define S21_ERPCMISMATCH    73              /* RPC version wrong */
#define S21_EPROGUNAVAIL    74              /* RPC prog. not avail */
#define S21_EPROGMISMATCH   75              /* Program version wrong */
#define S21_EPROCUNAVAIL    76              /* Bad procedure for program */
#endif

#define S21_ENOLCK          77              /* No locks available */
#define S21_ENOSYS          78              /* Function not implemented */

#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_EFTYPE          79              /* Inappropriate file type or format */
#define S21_EAUTH           80              /* Authentication error */
#define S21_ENEEDAUTH       81              /* Need authenticator */

/* Intelligent device errors */
#define S21_EPWROFF         82      /* Device power is off */
#define S21_EDEVERR         83      /* Device error, e.g. paper out */
#endif

#define S21_EOVERFLOW       84              /* Value too large to be stored in data type */

/* Program loading errors */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_EBADEXEC        85      /* Bad executable */
#define S21_EBADARCH        86      /* Bad CPU type in executable */
#define S21_ESHLIBVERS      87      /* Shared library version mismatch */
#define S21_EBADMACHO       88      /* Malformed Macho file */
#endif

#define S21_ECANCELED       89              /* Operation canceled */

#define S21_EIDRM           90              /* Identifier removed */
#define S21_ENOMSG          91              /* No message of desired type */
#define S21_EILSEQ          92              /* Illegal byte sequence */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define ENOATTR         93              /* Attribute not found */
#endif

#define S21_EBADMSG         94              /* Bad message */
#define S21_EMULTIHOP       95              /* Reserved */
#define S21_ENODATA         96              /* No message available on STREAM */
#define S21_ENOLINK         97              /* Reserved */
#define S21_ENOSR           98              /* No STREAM resources */
#define S21_ENOSTR          99              /* Not a STREAM */
#define S21_EPROTO          100             /* Protocol error */
#define S21_ETIME           101             /* STREAM ioctl timeout */

/* This value is only discrete when compiling __DARWIN_UNIX03, or KERNEL */
#define S21_EOPNOTSUPP      102             /* Operation not supported on socket */

#define S21_ENOPOLICY       103             /* No such policy registered */

#if __DARWIN_C_LEVEL >= 200809L
#define S21_ENOTRECOVERABLE 104             /* State not recoverable */
#define S21_EOWNERDEAD      105             /* Previous owner died */
#endif

#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define S21_EQFULL          106             /* Interface output queue is full */
#define S21_ELAST           106             /* Must be equal largest errno */
#endif

/* pseudo-errors returned inside kernel to modify return to process */
#define S21_ERESTART        (-1)            /* restart syscall */
#define S21_EJUSTRETURN     (-2)            /* don't modify regs, just return */
#endif /* __APPLE__ */

#endif /* MY_ERRNO_H */
