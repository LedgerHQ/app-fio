# Sign Transaction allowed commands sequences

Hashes in the list of allowed hashes come from a run of the app in compiled with `DEVEL=1`. 
Here follows the excrept of the log containing all allowed command sequences. Note that integrity hash is validated only on DH\_END and FINISH commands. This can be obtained by `make get_allowed_sequences_from_logs`

11:55:52.009 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionTrnsfiopubky
11:55:52.516:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:55:52.938:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:55:52.995:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:55:53.037:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000980ad20ca85be0e1d195ba85e7cd01
11:55:53.074:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e135472616e736665722046494f20746f6b656e73
11:55:53.476:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:55:53.521:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:55:53.569:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:55:53.624:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:55:53.660:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050c5061796565205075626b6579
11:55:54.000:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f0506416d6f756e74
11:55:54.462:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:55:54.842:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:55:54.892:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:55:54.956:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:55:54.986:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:55:55.031:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:55:55.384:seproxyhal: printf: Integrity check for: {0x72, 0x0b, 0x29, 0xb9, 0xb7, 0x06, 0xaa, 0xac, 0xdd, 0x35, 0xa7, 0xae, 0xef, 0xde, 0x25, 0x59, 0x1a, 0x55, 0x46, 0x06, 0x16, 0x54, 0x82, 0x78, 0x84, 0x16, 0x83, 0xe1, 0xf0, 0xd7, 0x98, 0x73}
11:55:57.102:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:55:57.561:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:55:57.616:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:55:57.670:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000980ad20ca85be0e1d195ba85e7cd01
11:55:57.707:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e135472616e736665722046494f20746f6b656e73
11:55:58.068:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:55:58.111:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:55:58.172:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:55:58.215:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:55:58.258:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050c5061796565205075626b6579
11:55:58.783:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f0506416d6f756e74
11:55:59.219:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:55:59.577:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:55:59.624:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:55:59.680:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:55:59.714:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:55:59.786:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:56:00.068:seproxyhal: printf: Integrity check for: {0x72, 0x0b, 0x29, 0xb9, 0xb7, 0x06, 0xaa, 0xac, 0xdd, 0x35, 0xa7, 0xae, 0xef, 0xde, 0x25, 0x59, 0x1a, 0x55, 0x46, 0x06, 0x16, 0x54, 0x82, 0x78, 0x84, 0x16, 0x83, 0xe1, 0xf0, 0xd7, 0x98, 0x73}
11:56:01.250:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:01.532:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:01.913:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:56:01.978:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:56:02.033:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000980ad20ca85be0e1d195ba85e7cd01
11:56:02.085:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e135472616e736665722046494f20746f6b656e73
11:56:02.426:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:56:02.466:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:02.523:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:56:02.566:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:02.604:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050c5061796565205075626b6579
11:56:02.947:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f0506416d6f756e74
11:56:03.349:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:56:03.779:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:03.825:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:56:03.880:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:03.917:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:56:03.972:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:56:04.283:seproxyhal: printf: Integrity check for: {0x72, 0x0b, 0x29, 0xb9, 0xb7, 0x06, 0xaa, 0xac, 0xdd, 0x35, 0xa7, 0xae, 0xef, 0xde, 0x25, 0x59, 0x1a, 0x55, 0x46, 0x06, 0x16, 0x54, 0x82, 0x78, 0x84, 0x16, 0x83, 0xe1, 0xf0, 0xd7, 0x98, 0x73}
11:56:06.214:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:06.639:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:56:06.688:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:56:06.732:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000980ad20ca85be0e1d195ba85e7cd01
11:56:06.789:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e135472616e736665722046494f20746f6b656e73
11:56:07.133:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:56:07.167:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:07.214:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:56:07.255:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:07.291:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050c5061796565205075626b6579
11:56:07.688:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f0506416d6f756e74
11:56:08.108:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:56:08.589:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:08.640:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:56:08.700:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:08.728:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:56:08.766:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:56:09.176:seproxyhal: printf: Integrity check for: {0x72, 0x0b, 0x29, 0xb9, 0xb7, 0x06, 0xaa, 0xac, 0xdd, 0x35, 0xa7, 0xae, 0xef, 0xde, 0x25, 0x59, 0x1a, 0x55, 0x46, 0x06, 0x16, 0x54, 0x82, 0x78, 0x84, 0x16, 0x83, 0xe1, 0xf0, 0xd7, 0x98, 0x73}
11:56:10.234 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionTrnsfiopubky
11:56:13.404 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionNewfundsreq
11:56:13.645:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:14.055:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:56:14.098:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:56:14.141:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b00acba384dbdb89a01
11:56:14.202:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0d526571756573742046756e6473
11:56:14.554:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:56:14.591:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:14.651:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:56:14.715:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:14.754:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:56:15.240:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:56:15.620:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 170340000000000000002801000000000000
11:56:15.670:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:56:16.342:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:56:16.906:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:56:17.528:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:56:18.207:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:56:18.958:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:56:19.132:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:56:19.481:seproxyhal: printf: Integrity check for: {0x04, 0x68, 0x6b, 0x09, 0xf5, 0x1d, 0x68, 0xb0, 0x8a, 0x0d, 0x0c, 0x6f, 0xac, 0x1a, 0x53, 0x37, 0x05, 0xe4, 0x02, 0x8a, 0x86, 0xf0, 0xc5, 0x2f, 0xb9, 0x2c, 0x2c, 0x09, 0xe1, 0x30, 0x09, 0x52}
11:56:20.085:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:20.139:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:56:20.649:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:20.704:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:56:20.766:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:20.794:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:56:20.836:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:20.883:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:56:20.939:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:56:21.302:seproxyhal: printf: Integrity check for: {0x23, 0x27, 0x7c, 0x5c, 0x25, 0x48, 0x1d, 0xa2, 0xa8, 0x97, 0xa5, 0xf2, 0xb7, 0xa3, 0x66, 0x1e, 0x35, 0xd7, 0x89, 0x90, 0x61, 0xad, 0x9b, 0x00, 0x91, 0xc2, 0x53, 0x30, 0xb2, 0x6b, 0x42, 0xca}
11:56:22.455:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:22.813:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:56:22.875:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:56:22.920:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b00acba384dbdb89a01
11:56:22.957:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0d526571756573742046756e6473
11:56:23.399:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:56:23.457:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:23.520:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:56:23.572:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:23.637:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:56:24.074:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:56:24.518:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 170340000000000000002801000000000000
11:56:24.571:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:56:25.197:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:56:25.740:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:56:26.416:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:56:26.922:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:56:27.374:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:56:27.585:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:56:27.926:seproxyhal: printf: Integrity check for: {0x04, 0x68, 0x6b, 0x09, 0xf5, 0x1d, 0x68, 0xb0, 0x8a, 0x0d, 0x0c, 0x6f, 0xac, 0x1a, 0x53, 0x37, 0x05, 0xe4, 0x02, 0x8a, 0x86, 0xf0, 0xc5, 0x2f, 0xb9, 0x2c, 0x2c, 0x09, 0xe1, 0x30, 0x09, 0x52}
11:56:28.414:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:28.465:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:56:28.833:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:28.879:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:56:28.930:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:28.961:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:56:29.001:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:29.041:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:56:29.112:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:56:29.428:seproxyhal: printf: Integrity check for: {0x23, 0x27, 0x7c, 0x5c, 0x25, 0x48, 0x1d, 0xa2, 0xa8, 0x97, 0xa5, 0xf2, 0xb7, 0xa3, 0x66, 0x1e, 0x35, 0xd7, 0x89, 0x90, 0x61, 0xad, 0x9b, 0x00, 0x91, 0xc2, 0x53, 0x30, 0xb2, 0x6b, 0x42, 0xca}
11:56:31.298:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:31.691:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:56:31.733:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:56:31.762:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b00acba384dbdb89a01
11:56:31.813:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0d526571756573742046756e6473
11:56:32.260:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:56:32.298:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:32.336:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:56:32.382:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:32.429:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:56:32.803:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:56:33.176:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 170340000000000000002801000000000000
11:56:33.228:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:56:33.889:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:56:34.564:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:56:35.260:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:56:35.746:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:56:36.289:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:56:36.535:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:56:36.869:seproxyhal: printf: Integrity check for: {0x04, 0x68, 0x6b, 0x09, 0xf5, 0x1d, 0x68, 0xb0, 0x8a, 0x0d, 0x0c, 0x6f, 0xac, 0x1a, 0x53, 0x37, 0x05, 0xe4, 0x02, 0x8a, 0x86, 0xf0, 0xc5, 0x2f, 0xb9, 0x2c, 0x2c, 0x09, 0xe1, 0x30, 0x09, 0x52}
11:56:37.591:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:37.641:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:56:38.162:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:38.239:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:56:38.286:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:38.324:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:56:38.383:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:38.424:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:56:38.484:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:56:38.812:seproxyhal: printf: Integrity check for: {0x23, 0x27, 0x7c, 0x5c, 0x25, 0x48, 0x1d, 0xa2, 0xa8, 0x97, 0xa5, 0xf2, 0xb7, 0xa3, 0x66, 0x1e, 0x35, 0xd7, 0x89, 0x90, 0x61, 0xad, 0x9b, 0x00, 0x91, 0xc2, 0x53, 0x30, 0xb2, 0x6b, 0x42, 0xca}
11:56:39.812:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:40.277:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:56:40.327:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:56:40.373:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b00acba384dbdb89a01
11:56:40.405:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0d526571756573742046756e6473
11:56:40.792:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:56:40.835:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:40.899:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:56:40.939:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:40.987:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:56:41.497:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:56:41.871:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 170340000000000000002801000000000000
11:56:41.921:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:56:42.603:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:56:43.076:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:56:43.576:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:56:44.061:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:56:44.566:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:56:44.767:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:56:45.106:seproxyhal: printf: Integrity check for: {0x04, 0x68, 0x6b, 0x09, 0xf5, 0x1d, 0x68, 0xb0, 0x8a, 0x0d, 0x0c, 0x6f, 0xac, 0x1a, 0x53, 0x37, 0x05, 0xe4, 0x02, 0x8a, 0x86, 0xf0, 0xc5, 0x2f, 0xb9, 0x2c, 0x2c, 0x09, 0xe1, 0x30, 0x09, 0x52}
11:56:45.853:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:45.891:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:56:46.429:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:46.475:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:56:46.527:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:46.559:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:56:46.607:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:56:46.656:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:56:46.709:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:56:47.030:seproxyhal: printf: Integrity check for: {0x23, 0x27, 0x7c, 0x5c, 0x25, 0x48, 0x1d, 0xa2, 0xa8, 0x97, 0xa5, 0xf2, 0xb7, 0xa3, 0x66, 0x1e, 0x35, 0xd7, 0x89, 0x90, 0x61, 0xad, 0x9b, 0x00, 0x91, 0xc2, 0x53, 0x30, 0xb2, 0x6b, 0x42, 0xca}
11:56:47.963 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionNewfundsreq
11:56:51.395 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionRecordobt
11:56:51.652:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:56:52.052:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:56:52.101:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:56:52.140:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b0000c887a64b91ba01
11:56:52.184:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0f5265636f7264206d65746164617461
11:56:52.610:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:56:52.654:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:56:52.723:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:56:52.770:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:56:52.815:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000060a52657175657374204944
11:56:53.287:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:56:53.676:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:56:54.067:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17034000000000000000b001000000000000
11:56:54.109:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:56:54.779:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796572205075626c69632041646472
11:56:55.281:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:56:55.923:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:56:56.561:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:56:57.045:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:56:57.568:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000506537461747573
11:56:58.101:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005064f6274204944
11:56:58.804:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:56:59.057:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:56:59.414:seproxyhal: printf: Integrity check for: {0xb9, 0xb3, 0x6e, 0x49, 0xe5, 0xc2, 0xac, 0x9e, 0x27, 0xd7, 0xbf, 0xd1, 0x6c, 0x33, 0xdb, 0xa4, 0x79, 0x36, 0xc3, 0x6f, 0xa2, 0xac, 0x28, 0xdc, 0x9e, 0xd8, 0xa8, 0x5b, 0x67, 0x33, 0x6f, 0x44}
11:57:00.113:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:00.152:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:00.513:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:00.558:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:57:00.621:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:00.659:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:00.719:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:00.757:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:00.826:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:01.111:seproxyhal: printf: Integrity check for: {0x90, 0xd9, 0xdd, 0xf7, 0x0d, 0x88, 0x32, 0xc2, 0x8a, 0xb2, 0xa8, 0xb2, 0xd5, 0xae, 0x08, 0x21, 0x54, 0xc6, 0xcf, 0x76, 0x4e, 0x77, 0x5e, 0x22, 0xde, 0x34, 0x63, 0x10, 0x4b, 0x60, 0xd4, 0x73}
11:57:02.443:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:02.921:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:02.962:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:03.006:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b0000c887a64b91ba01
11:57:03.040:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0f5265636f7264206d65746164617461
11:57:03.407:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:03.445:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:03.501:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:03.546:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:03.585:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000060a52657175657374204944
11:57:03.944:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:57:04.326:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:57:04.695:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17034000000000000000b001000000000000
11:57:04.736:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:57:05.312:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796572205075626c69632041646472
11:57:05.870:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:57:06.573:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:57:07.222:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:57:07.717:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:57:08.220:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000506537461747573
11:57:08.727:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005064f6274204944
11:57:09.236:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:57:09.420:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:57:09.761:seproxyhal: printf: Integrity check for: {0xb9, 0xb3, 0x6e, 0x49, 0xe5, 0xc2, 0xac, 0x9e, 0x27, 0xd7, 0xbf, 0xd1, 0x6c, 0x33, 0xdb, 0xa4, 0x79, 0x36, 0xc3, 0x6f, 0xa2, 0xac, 0x28, 0xdc, 0x9e, 0xd8, 0xa8, 0x5b, 0x67, 0x33, 0x6f, 0x44}
11:57:10.506:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:10.553:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:11.108:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:11.150:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:57:11.202:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:11.232:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:11.271:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:11.313:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:11.357:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:11.688:seproxyhal: printf: Integrity check for: {0x90, 0xd9, 0xdd, 0xf7, 0x0d, 0x88, 0x32, 0xc2, 0x8a, 0xb2, 0xa8, 0xb2, 0xd5, 0xae, 0x08, 0x21, 0x54, 0xc6, 0xcf, 0x76, 0x4e, 0x77, 0x5e, 0x22, 0xde, 0x34, 0x63, 0x10, 0x4b, 0x60, 0xd4, 0x73}
11:57:12.789:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:13.231:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:13.272:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:13.337:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b0000c887a64b91ba01
11:57:13.378:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0f5265636f7264206d65746164617461
11:57:13.736:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:13.789:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:13.855:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:13.896:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:13.955:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000060a52657175657374204944
11:57:13.999:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:57:14.398:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:57:14.788:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17034000000000000000b001000000000000
11:57:14.838:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:57:15.522:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796572205075626c69632041646472
11:57:16.203:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:57:16.691:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:57:17.197:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:57:17.660:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:57:18.160:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000506537461747573
11:57:18.844:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005064f6274204944
11:57:19.511:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:57:19.690:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:57:20.020:seproxyhal: printf: Integrity check for: {0xb9, 0xb3, 0x6e, 0x49, 0xe5, 0xc2, 0xac, 0x9e, 0x27, 0xd7, 0xbf, 0xd1, 0x6c, 0x33, 0xdb, 0xa4, 0x79, 0x36, 0xc3, 0x6f, 0xa2, 0xac, 0x28, 0xdc, 0x9e, 0xd8, 0xa8, 0x5b, 0x67, 0x33, 0x6f, 0x44}
11:57:20.779:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:20.819:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:21.155:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:21.198:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:57:21.248:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:21.277:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:21.320:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:21.362:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:21.401:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:21.738:seproxyhal: printf: Integrity check for: {0x90, 0xd9, 0xdd, 0xf7, 0x0d, 0x88, 0x32, 0xc2, 0x8a, 0xb2, 0xa8, 0xb2, 0xd5, 0xae, 0x08, 0x21, 0x54, 0xc6, 0xcf, 0x76, 0x4e, 0x77, 0x5e, 0x22, 0xde, 0x34, 0x63, 0x10, 0x4b, 0x60, 0xd4, 0x73}
11:57:23.356:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:23.858:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:23.914:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:23.956:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b0000c887a64b91ba01
11:57:23.994:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0f5265636f7264206d65746164617461
11:57:24.399:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:24.439:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:24.489:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:24.528:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:24.575:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000060a52657175657374204944
11:57:24.658:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965722046494f2048616e646c65
11:57:25.065:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000051050617965652046494f2048616e646c65
11:57:25.448:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17034000000000000000b001000000000000
11:57:25.496:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 08. p2: 00, constdata: 
11:57:26.160:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796572205075626c69632041646472
11:57:26.655:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005115061796565205075626c69632041646472
11:57:27.160:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000510416d6f756e7420726571756573746564
11:57:27.679:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:57:28.382:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a546f6b656e20636f6465
11:57:29.115:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000506537461747573
11:57:29.807:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005064f6274204944
11:57:30.296:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 2001000000000000000000000000000000000200
11:57:30.478:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 09. p2: 00, constdata: 
11:57:30.783:seproxyhal: printf: Integrity check for: {0xb9, 0xb3, 0x6e, 0x49, 0xe5, 0xc2, 0xac, 0x9e, 0x27, 0xd7, 0xbf, 0xd1, 0x6c, 0x33, 0xdb, 0xa4, 0x79, 0x36, 0xc3, 0x6f, 0xa2, 0xac, 0x28, 0xdc, 0x9e, 0xd8, 0xa8, 0x5b, 0x67, 0x33, 0x6f, 0x44}
11:57:31.334:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:31.375:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:31.739:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:31.782:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
11:57:31.841:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:31.874:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:31.913:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:31.957:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:32.009:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:32.395:seproxyhal: printf: Integrity check for: {0x90, 0xd9, 0xdd, 0xf7, 0x0d, 0x88, 0x32, 0xc2, 0x8a, 0xb2, 0xa8, 0xb2, 0xd5, 0xae, 0x08, 0x21, 0x54, 0xc6, 0xcf, 0x76, 0x4e, 0x77, 0x5e, 0x22, 0xde, 0x34, 0x63, 0x10, 0x4b, 0x60, 0xd4, 0x73}
11:57:33.521 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionRecordobt
11:57:36.980 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionAddaddress
11:57:37.426:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:37.873:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:37.918:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:37.955:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664523201
11:57:38.014:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e124d6170207075626c69632061646472657373
11:57:38.440:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:38.477:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:38.526:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:38.579:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:38.636:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:57:39.152:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 01
11:57:39.192:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:57:39.750:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:40.196:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:40.264:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:40.326:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:40.381:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:40.451:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:40.780:seproxyhal: printf: Integrity check for: {0xab, 0x0f, 0x5c, 0xce, 0x2f, 0xaf, 0x6b, 0x90, 0x93, 0xf3, 0xb5, 0xbe, 0xa9, 0x6a, 0x74, 0xa7, 0x70, 0xd2, 0x91, 0x68, 0xf7, 0x1f, 0xe5, 0x3d, 0x19, 0x74, 0xf7, 0xa5, 0x10, 0x39, 0x63, 0xc1}
11:57:42.072:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:42.538:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:42.600:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:42.641:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664523201
11:57:42.683:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e124d6170207075626c69632061646472657373
11:57:43.044:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:43.080:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:43.120:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:43.193:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:43.230:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:57:43.761:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 02
11:57:43.806:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:57:44.351:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:57:44.755:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:45.144:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:45.203:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:45.256:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:45.286:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:45.338:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:45.698:seproxyhal: printf: Integrity check for: {0x30, 0x73, 0x00, 0xed, 0x8d, 0x10, 0x65, 0x24, 0x7f, 0xa3, 0xdd, 0x2a, 0x1b, 0x7c, 0x90, 0xa8, 0xb2, 0x6f, 0xaf, 0xad, 0xb6, 0xf7, 0xa7, 0x5f, 0x91, 0x92, 0x97, 0xe5, 0xf1, 0xb1, 0x21, 0x96}
11:57:47.081:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:47.584:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:47.660:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:47.700:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664523201
11:57:47.737:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e124d6170207075626c69632061646472657373
11:57:48.070:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:48.115:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:48.161:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:48.199:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:48.240:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:57:48.593:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 03
11:57:48.639:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:57:49.003:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:57:49.382:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672033
11:57:49.763:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:50.193:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:50.238:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:50.288:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:50.326:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:50.369:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:50.730:seproxyhal: printf: Integrity check for: {0x13, 0x02, 0x4a, 0xa0, 0xa0, 0xea, 0x70, 0xc8, 0x11, 0x52, 0x2d, 0x67, 0x17, 0x41, 0xcd, 0x8c, 0x4e, 0xf6, 0x80, 0x31, 0x7c, 0x4d, 0x5c, 0xa0, 0xf2, 0xfa, 0x3c, 0x4b, 0xb1, 0x85, 0xc5, 0xcd}
11:57:51.893:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:52.342:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:52.388:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:52.431:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664523201
11:57:52.497:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e124d6170207075626c69632061646472657373
11:57:52.862:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:52.904:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:52.957:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:52.995:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:53.048:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:57:53.578:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 04
11:57:53.623:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:57:54.016:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:57:54.423:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672033
11:57:54.801:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672034
11:57:55.208:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:57:55.597:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:55.643:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:57:55.698:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:57:55.726:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:57:55.790:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:57:56.084:seproxyhal: printf: Integrity check for: {0x8e, 0x26, 0x84, 0x94, 0x40, 0xd8, 0xcd, 0xf9, 0xd0, 0x1a, 0x08, 0x17, 0xaa, 0x0b, 0x57, 0x33, 0xf6, 0x48, 0xf0, 0x1f, 0xea, 0xfd, 0x51, 0xb4, 0xac, 0x3d, 0x18, 0xad, 0x87, 0x3f, 0xb9, 0xa4}
11:57:57.285:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:57:57.789:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:57:57.854:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:57:57.909:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664523201
11:57:57.941:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e124d6170207075626c69632061646472657373
11:57:58.488:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:57:58.547:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:57:58.596:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:57:58.643:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:57:58.690:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:57:59.185:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 05
11:57:59.226:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:57:59.601:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:57:59.969:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672033
11:58:00.414:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672034
11:58:00.820:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672035
11:58:01.216:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:01.667:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:01.714:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:01.775:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:01.821:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:01.886:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:02.218:seproxyhal: printf: Integrity check for: {0xf6, 0x9c, 0xe5, 0x0f, 0x3c, 0xdf, 0xa4, 0x1e, 0x00, 0x7e, 0xf3, 0xb0, 0x29, 0xc4, 0x3b, 0xc7, 0x92, 0x3e, 0xb3, 0x78, 0x71, 0x7d, 0xed, 0x96, 0x1c, 0x41, 0x5a, 0x4c, 0x82, 0x50, 0xc9, 0xa1}
11:58:03.481 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionAddaddress
11:58:06.890 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionRemaddress
11:58:07.400:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:07.899:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:07.950:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:08.008:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664a4ba01
11:58:08.051:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1e52656d6f7665207075626c69632061646472657373206d617070696e6773
11:58:08.412:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:08.448:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:08.501:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:08.549:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:08.592:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:09.098:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 01
11:58:09.151:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:58:09.695:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:10.118:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:10.168:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:10.234:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:10.271:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:10.316:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:10.703:seproxyhal: printf: Integrity check for: {0xe7, 0xa8, 0xd4, 0xed, 0x82, 0xd2, 0x60, 0x32, 0x54, 0x5a, 0xc2, 0xc6, 0x73, 0x73, 0xfb, 0xf5, 0xfa, 0xa6, 0x8f, 0x2f, 0xb4, 0xb8, 0x91, 0xe3, 0xe8, 0x11, 0x6a, 0xca, 0x08, 0xbf, 0x59, 0xe1}
11:58:11.922:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:12.433:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:12.497:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:12.530:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664a4ba01
11:58:12.584:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1e52656d6f7665207075626c69632061646472657373206d617070696e6773
11:58:13.117:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:13.166:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:13.229:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:13.282:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:13.331:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:13.721:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 02
11:58:13.760:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:58:14.142:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:58:14.538:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:14.925:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:14.979:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:15.047:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:15.086:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:15.150:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:15.534:seproxyhal: printf: Integrity check for: {0x26, 0xe5, 0x21, 0x0f, 0x8f, 0xc8, 0x77, 0x8e, 0xb7, 0x24, 0x97, 0x32, 0x20, 0xa2, 0xbc, 0x85, 0xbe, 0x11, 0x10, 0xb8, 0x39, 0x8d, 0xd2, 0x7e, 0x9d, 0x3a, 0xbc, 0xaf, 0x58, 0x1a, 0x48, 0x79}
11:58:16.775:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:17.277:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:17.321:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:17.362:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664a4ba01
11:58:17.419:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1e52656d6f7665207075626c69632061646472657373206d617070696e6773
11:58:17.774:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:17.821:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:17.890:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:17.942:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:18.014:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:18.396:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 03
11:58:18.435:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:58:18.802:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:58:19.170:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672033
11:58:19.560:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:19.942:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:19.995:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:20.056:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:20.090:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:20.131:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:20.451:seproxyhal: printf: Integrity check for: {0xe0, 0xa6, 0x06, 0xd1, 0x34, 0xb3, 0xbf, 0xfd, 0x72, 0x6f, 0x69, 0xf7, 0xd1, 0xa5, 0x68, 0x78, 0xd8, 0xad, 0x15, 0x66, 0xd4, 0x1e, 0xdc, 0x30, 0x1d, 0xbe, 0xea, 0x09, 0x82, 0xf1, 0x3d, 0xb}
11:58:21.664:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:22.118:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:22.171:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:22.214:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664a4ba01
11:58:22.266:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1e52656d6f7665207075626c69632061646472657373206d617070696e6773
11:58:22.594:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:22.635:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:22.691:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:22.730:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:22.779:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:23.153:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 04
11:58:23.197:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:58:23.566:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:58:23.980:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672033
11:58:24.370:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672034
11:58:24.745:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:25.153:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:25.221:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:25.264:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:25.295:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:25.353:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:25.715:seproxyhal: printf: Integrity check for: {0xd6, 0xcc, 0x05, 0x60, 0xfd, 0xa9, 0x7d, 0x55, 0xb2, 0x49, 0x4e, 0x2a, 0x59, 0x13, 0xe3, 0xe4, 0x3c, 0xf7, 0x3e, 0x5e, 0x28, 0x3d, 0x15, 0xe4, 0x68, 0x2d, 0x23, 0x3e, 0x7c, 0x9b, 0x0b, 0x63}
11:58:27.036:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:27.518:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:27.578:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:27.631:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa664a4ba01
11:58:27.671:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1e52656d6f7665207075626c69632061646472657373206d617070696e6773
11:58:28.015:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:28.059:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:28.142:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:28.184:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:28.235:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:28.614:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 05
11:58:28.679:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672031
11:58:29.201:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672032
11:58:29.599:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672033
11:58:29.980:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672034
11:58:30.381:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 21010000000000000000000000000000000005094d617070696e672035
11:58:30.768:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:31.198:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:31.258:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:31.313:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:31.344:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:31.396:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:31.754:seproxyhal: printf: Integrity check for: {0xb5, 0xf3, 0xed, 0x5f, 0x34, 0x48, 0x5d, 0xa3, 0xa4, 0x93, 0x10, 0xf0, 0x09, 0x8d, 0xfb, 0x71, 0x34, 0x5e, 0x0f, 0x6a, 0xc8, 0x42, 0x16, 0xc0, 0xe1, 0xb9, 0xed, 0x11, 0x09, 0x7c, 0x22, 0x30}
11:58:32.661 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionRemaddress
11:58:36.065 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionAddnft
11:58:36.561:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:37.052:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:37.091:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:37.135:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00000000e435533201
11:58:37.190:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e084d6170206e667473
11:58:37.547:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:37.599:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:37.665:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:37.713:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:37.776:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:38.150:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 01
11:58:38.189:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203100
11:58:38.606:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:58:38.999:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:58:39.425:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:58:39.798:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:39.870:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000041000000000000000200
11:58:39.935:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:39.979:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:40.339:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:40.388:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:40.439:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:40.489:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:40.547:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:40.918:seproxyhal: printf: Integrity check for: {0x3b, 0x19, 0xb4, 0x63, 0xcd, 0xba, 0xd4, 0x75, 0x76, 0x78, 0x03, 0x92, 0x17, 0xae, 0xd5, 0xea, 0x13, 0xe1, 0xe8, 0xab, 0xc8, 0xc8, 0x35, 0x7b, 0x50, 0xc8, 0xef, 0x5c, 0x1c, 0x2e, 0xe1, 0x72}
11:58:42.254:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:42.741:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:42.813:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:42.855:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00000000e435533201
11:58:42.891:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e084d6170206e667473
11:58:43.267:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:43.308:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:43.360:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:43.401:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:43.452:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:43.914:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 02
11:58:43.950:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203100
11:58:44.330:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:58:44.726:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:58:45.097:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:58:45.497:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:45.551:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000041000000000000000200
11:58:45.605:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:45.646:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203200
11:58:46.069:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:58:46.534:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:58:46.933:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:58:47.318:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:47.379:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000041000000000000000200
11:58:47.448:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:47.518:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:47.991:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:48.059:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:48.128:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:48.171:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:48.213:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:48.562:seproxyhal: printf: Integrity check for: {0x39, 0x31, 0xa7, 0x1c, 0x07, 0x8e, 0x5e, 0x28, 0x20, 0x90, 0x3e, 0x25, 0xe1, 0x81, 0x8f, 0xea, 0x46, 0xda, 0x16, 0xd9, 0xd2, 0x56, 0xf3, 0x91, 0x7e, 0x5a, 0xe4, 0x5b, 0x94, 0x73, 0x45, 0xdf}
11:58:49.912:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:58:50.380:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:58:50.433:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:58:50.472:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00000000e435533201
11:58:50.519:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e084d6170206e667473
11:58:50.867:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:58:50.905:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:50.965:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:58:51.011:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:58:51.068:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:58:51.565:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 03
11:58:51.600:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203100
11:58:51.964:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:58:52.360:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:58:52.727:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:58:53.174:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:53.220:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000041000000000000000200
11:58:53.273:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:53.327:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203200
11:58:53.683:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:58:54.060:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:58:54.477:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:58:54.838:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:54.889:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000041000000000000000200
11:58:54.942:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:55.005:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203300
11:58:55.377:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:58:55.744:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:58:56.125:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:58:56.522:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:56.589:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000041000000000000000200
11:58:56.645:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000082000000000000000200
11:58:56.710:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:58:57.069:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:58:57.152:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:58:57.228:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:58:57.268:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:58:57.307:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:58:57.695:seproxyhal: printf: Integrity check for: {0xea, 0xa0, 0xae, 0x50, 0x58, 0x10, 0x80, 0x4b, 0x52, 0x1e, 0x91, 0x0b, 0xc9, 0x64, 0xad, 0x73, 0x76, 0xd9, 0x37, 0xfa, 0x33, 0xab, 0xcf, 0x1f, 0xf8, 0x71, 0x50, 0xf9, 0xba, 0xea, 0x4b, 0x2d}
11:58:58.904 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionAddnft
11:59:02.230 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionRemnft
11:59:02.665:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:03.073:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:03.131:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:03.173:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00000000e435a5ba01
11:59:03.212:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1352656d6f7665206e6674206d617070696e6773
11:59:03.562:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:03.601:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:03.668:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:03.712:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:03.750:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:59:04.116:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 01
11:59:04.165:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203100
11:59:04.530:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:59:04.921:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:59:05.296:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:59:05.699:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:06.113:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:06.180:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:06.238:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:06.270:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:06.328:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:06.677:seproxyhal: printf: Integrity check for: {0xeb, 0x12, 0x64, 0xc2, 0x90, 0xa6, 0x78, 0x09, 0xe1, 0x56, 0xdf, 0x06, 0x15, 0xd6, 0x64, 0x7e, 0x47, 0xb9, 0x92, 0x95, 0x92, 0x2b, 0x51, 0x40, 0xe8, 0xc9, 0x82, 0x7f, 0x68, 0x4f, 0xe6, 0xfc}
11:59:07.915:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:08.373:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:08.420:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:08.460:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00000000e435a5ba01
11:59:08.499:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1352656d6f7665206e6674206d617070696e6773
11:59:08.926:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:08.970:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:09.039:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:09.076:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:09.122:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:59:09.650:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 02
11:59:09.687:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203100
11:59:10.056:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:59:10.468:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:59:10.948:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:59:11.344:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203200
11:59:11.735:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:59:12.112:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:59:12.574:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:59:13.037:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:13.436:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:13.490:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:13.545:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:13.578:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:13.616:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:13.989:seproxyhal: printf: Integrity check for: {0x62, 0x62, 0x11, 0x4f, 0xad, 0x75, 0x96, 0x76, 0x7f, 0x65, 0x43, 0xd0, 0x61, 0x91, 0x35, 0x1d, 0x6e, 0xbf, 0x64, 0xd6, 0x94, 0x1c, 0x25, 0xbb, 0x59, 0xc1, 0x26, 0xe5, 0x94, 0xce, 0x89, 0xcf}
11:59:15.299:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:15.768:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:15.839:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:15.879:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00000000e435a5ba01
11:59:15.919:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1352656d6f7665206e6674206d617070696e6773
11:59:16.261:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:16.300:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:16.356:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:16.416:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:16.485:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:59:16.943:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 03
11:59:16.979:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203100
11:59:17.327:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:59:17.793:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:59:18.196:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:59:18.578:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203200
11:59:18.963:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:59:19.368:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:59:19.717:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:59:20.192:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 094d617070696e67203300
11:59:20.581:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
11:59:21.014:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402020000000000000082000000000000000510436f6e74726163742061646472657373
11:59:21.392:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000008200000000000000050c4e465420546f6b656e204944
11:59:21.757:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:22.166:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:22.224:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:22.276:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:22.318:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:22.365:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:22.693:seproxyhal: printf: Integrity check for: {0x68, 0x4d, 0x19, 0x1b, 0xec, 0x18, 0x69, 0x3a, 0xc2, 0x2a, 0x79, 0xe3, 0xbc, 0xe5, 0xa4, 0xc6, 0xe1, 0xa5, 0xb3, 0xfd, 0x6e, 0x04, 0xb0, 0x33, 0xd4, 0x2f, 0xe6, 0x1b, 0x5d, 0x51, 0x7b, 0x80}
11:59:23.671 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionRemnft
11:59:26.982 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionOtherFioAddress
11:59:27.475:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:27.907:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:27.983:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:28.022:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00c04dc9c468a4ba01
11:59:28.077:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e2252656d6f766520616c6c207075626c69632061646472657373206d617070696e6773
11:59:28.568:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:28.611:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:28.669:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:28.707:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:28.746:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:59:29.118:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:29.579:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:29.624:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:29.684:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:29.733:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:29.792:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:30.112:seproxyhal: printf: Integrity check for: {0xf7, 0xf1, 0xe3, 0xcc, 0xda, 0xbc, 0x21, 0x9c, 0xb7, 0xef, 0xbe, 0x45, 0x6c, 0x87, 0xf3, 0x59, 0x76, 0xc9, 0x9c, 0x0d, 0xe9, 0xac, 0x10, 0x93, 0x46, 0xda, 0x1f, 0x91, 0xd3, 0x78, 0x1b, 0x53}
11:59:31.406:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:31.903:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:31.944:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:31.991:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b000056314d7d523201
11:59:32.052:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0b4164642042756e646c6573
11:59:32.497:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:32.550:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:32.603:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:32.645:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:32.682:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:59:33.208:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 14030000000000000000ffffffffffffff7f050b42756e646c652073657473
11:59:33.602:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:33.981:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:34.075:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:34.110:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:34.145:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:34.219:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:34.518:seproxyhal: printf: Integrity check for: {0x04, 0x7d, 0x85, 0x04, 0xb6, 0xb9, 0x21, 0x51, 0x19, 0x7d, 0x20, 0xc9, 0xe7, 0x9f, 0xc1, 0x81, 0x3e, 0xe4, 0xa0, 0xd5, 0xa2, 0x1d, 0x3c, 0x36, 0x66, 0x89, 0x01, 0x1a, 0x71, 0xe9, 0x2a, 0x8a}
11:59:35.909:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:36.396:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:36.438:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:36.482:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000c6eaa66498ba01
11:59:36.527:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1a52656769737465722046494f2043727970746f2048616e646c65
11:59:36.961:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:37.003:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:37.051:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:37.106:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:37.143:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:59:37.698:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050c4f776e6572205075626b6579
11:59:38.097:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:38.466:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:38.511:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:38.579:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:38.617:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:38.665:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:39.041:seproxyhal: printf: Integrity check for: {0x47, 0x75, 0xd1, 0x26, 0xa4, 0x4b, 0x48, 0x95, 0x2d, 0x84, 0x5e, 0x43, 0x06, 0x7e, 0x6b, 0x13, 0x42, 0x6f, 0xdd, 0x77, 0x55, 0x25, 0x9d, 0x6a, 0xfc, 0x7f, 0x83, 0xc0, 0x82, 0xc2, 0xeb, 0x4c}
11:59:40.557:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:41.028:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:41.071:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:41.115:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b003056372573d5ea01
11:59:41.156:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1a5472616e736665722046494f2043727970746f2048616e646c65
11:59:41.555:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:41.614:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:41.683:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:41.718:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:41.762:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
11:59:42.216:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050c4f776e6572205075626b6579
11:59:42.610:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:43.017:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:43.095:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:43.159:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:43.210:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:43.253:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:43.577:seproxyhal: printf: Integrity check for: {0x52, 0x44, 0x21, 0x4f, 0x79, 0xf9, 0xba, 0x27, 0x9e, 0x34, 0xd4, 0xfb, 0x35, 0x13, 0x7f, 0xc4, 0x06, 0xe6, 0xc7, 0x7d, 0x99, 0x51, 0x7e, 0xd4, 0xd2, 0x7d, 0x8e, 0x97, 0xf8, 0x1c, 0x34, 0x54}
11:59:44.750:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:45.247:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:45.290:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:45.335:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b000098ce489a98ba01
11:59:45.371:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1352656769737465722046494f20446f6d61696e
11:59:45.780:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:45.827:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:45.891:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:45.929:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:45.976:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000003f00000000000000050a46494f20446f6d61696e
11:59:46.466:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050c4f776e6572205075626b6579
11:59:46.879:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:47.239:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:47.297:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:47.363:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:47.391:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:47.433:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:47.821:seproxyhal: printf: Integrity check for: {0xf8, 0x73, 0x29, 0xbd, 0xc7, 0x2d, 0xaf, 0x8d, 0xdb, 0xac, 0xac, 0x28, 0xea, 0x24, 0x7a, 0xe1, 0x1a, 0x82, 0x97, 0x47, 0x4f, 0x9b, 0x59, 0x86, 0xcb, 0x27, 0xe5, 0xf9, 0x99, 0x1d, 0xf1, 0x43}
11:59:49.228:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:49.697:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:49.755:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:49.801:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00a6339226aea6ba01
11:59:49.840:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1052656e65772046494f20646f6d61696e
11:59:50.229:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:50.265:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:50.329:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:50.382:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:50.431:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000003f00000000000000050a46494f20446f6d61696e
11:59:50.770:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:51.184:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:51.243:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:51.290:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:51.337:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:51.389:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:51.763:seproxyhal: printf: Integrity check for: {0x2d, 0x26, 0x7c, 0x41, 0xf6, 0x32, 0x27, 0x91, 0x10, 0x76, 0x96, 0x39, 0x57, 0x0f, 0xe3, 0xf5, 0x56, 0x9b, 0x81, 0xa3, 0x02, 0xc9, 0x1d, 0x46, 0x95, 0x19, 0x0b, 0x26, 0x3b, 0x60, 0xf0, 0xe4}
11:59:53.169:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:53.666:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:53.716:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:53.761:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b70749dce489ab2c201
11:59:53.820:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e265365742046494f20446f6d61696e20726567697374726174696f6e207065726d697373696f6e
11:59:54.186:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:54.238:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:54.297:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:54.345:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:54.419:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000003f00000000000000050a46494f20446f6d61696e
11:59:54.810:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 01
11:59:54.863:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 044d616b65065075626c6963
11:59:55.394:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
11:59:55.795:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:55.843:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
11:59:55.894:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
11:59:55.927:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
11:59:55.974:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
11:59:56.395:seproxyhal: printf: Integrity check for: {0x2f, 0x1e, 0x4e, 0xa2, 0x81, 0x48, 0x5e, 0x01, 0x55, 0x1b, 0x4f, 0x20, 0x56, 0x7b, 0x97, 0x27, 0xba, 0xae, 0xad, 0x60, 0x5f, 0xb6, 0x83, 0xd7, 0x37, 0x4a, 0x0d, 0x06, 0xeb, 0xa0, 0xf8, 0xbb}
11:59:57.753:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
11:59:58.236:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
11:59:58.287:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
11:59:58.332:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b70749dce489ab2c201
11:59:58.388:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e265365742046494f20446f6d61696e20726567697374726174696f6e207065726d697373696f6e
11:59:58.715:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
11:59:58.754:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
11:59:58.826:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
11:59:58.877:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
11:59:58.923:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000003f00000000000000050a46494f20446f6d61696e
11:59:59.423:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00
11:59:59.465:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 044d616b650750726976617465
11:59:59.797:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:00.301:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:00.367:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:00:00.414:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:00.447:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:00.492:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:00.836:seproxyhal: printf: Integrity check for: {0xe4, 0x85, 0x22, 0x61, 0x22, 0x3b, 0xa3, 0x05, 0x42, 0xa0, 0xb6, 0x0d, 0x73, 0xbf, 0xf9, 0xcd, 0x82, 0x6a, 0x9c, 0x9b, 0x74, 0x70, 0x47, 0x5c, 0x61, 0x80, 0x31, 0x25, 0x46, 0xa9, 0x4f, 0x21}
12:00:02.201:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:02.720:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:02.769:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:02.819:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b00c07446d274d5ea01
12:00:02.856:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e135472616e736665722046494f20446f6d61696e
12:00:03.221:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:03.261:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:03.309:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:03.348:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:03.388:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000003f00000000000000050a46494f20446f6d61696e
12:00:03.757:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 04020100000000000000040000000100000005104e6577206f776e6572205075626b6579
12:00:04.136:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:04.596:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:04.653:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:00:04.703:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:04.736:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:04.805:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:05.130:seproxyhal: printf: Integrity check for: {0xf2, 0xef, 0xc6, 0x69, 0x8f, 0x05, 0x36, 0x14, 0x8b, 0x56, 0x1d, 0x43, 0xb2, 0x22, 0xfb, 0x42, 0xb9, 0x1f, 0x8d, 0xd8, 0x83, 0x07, 0xb7, 0xff, 0x87, 0x09, 0x47, 0xf1, 0xb8, 0x61, 0x52, 0xbb}
12:00:06.562:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:07.039:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:07.081:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:07.118:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 003056372503a85b0000ce6bc668a4ba01
12:00:07.169:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1752656d6f766520616c6c206e6674206d617070696e6773
12:00:07.578:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:07.620:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:07.676:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:07.715:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:07.753:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:00:08.267:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:08.634:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:08.719:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:00:08.770:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:08.828:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:08.872:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:09.237:seproxyhal: printf: Integrity check for: {0x21, 0xfb, 0x21, 0x50, 0xd1, 0x7b, 0xa2, 0x06, 0x4b, 0xe7, 0x52, 0xa8, 0x1f, 0xca, 0x68, 0xdf, 0x60, 0x62, 0x43, 0xeb, 0x75, 0x3c, 0x56, 0x9d, 0x97, 0x10, 0xc4, 0x24, 0x20, 0xba, 0xf4, 0x4d}
12:00:10.239 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionOtherFioAddress
12:00:13.651 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionOtherFioReqobt
12:00:14.160:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:14.614:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:14.678:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:14.726:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b60d54d734585a64101
12:00:14.767:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1443616e63656c2066756e64732072657175657374
12:00:15.131:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:15.169:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:15.215:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:15.253:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:15.292:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050a52657175657374204944
12:00:15.665:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:16.022:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:16.087:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
12:00:16.159:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:16.200:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:00:16.246:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:16.278:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:16.334:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:16.712:seproxyhal: printf: Integrity check for: {0x10, 0x21, 0x24, 0x06, 0xf8, 0xec, 0xc1, 0x2b, 0x09, 0x46, 0x00, 0x4c, 0x6c, 0x81, 0x01, 0x82, 0x67, 0xc8, 0x81, 0x68, 0x5a, 0x8a, 0x57, 0x6a, 0x7e, 0xb1, 0xb1, 0xf7, 0x6a, 0x7b, 0x4b, 0xae}
12:00:17.942:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:18.443:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:18.509:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:18.559:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00403ed4aa0ba85b60d54d7365a49eba01
12:00:18.598:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1452656a6563742066756e64732072657175657374
12:00:18.938:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:18.976:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:19.030:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:19.086:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:19.133:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050a52657175657374204944
12:00:19.625:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:20.021:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:20.096:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 020200000000000000000e000000000000004200
12:00:20.144:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:20.181:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:00:20.233:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:20.283:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:20.335:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:20.648:seproxyhal: printf: Integrity check for: {0xb8, 0x19, 0x6b, 0x10, 0x79, 0x4b, 0x3f, 0xe1, 0x50, 0xb3, 0xa1, 0xdb, 0x0f, 0x74, 0xd3, 0x82, 0xa1, 0x6c, 0xad, 0xdb, 0xb1, 0x0d, 0xd0, 0x20, 0xc2, 0xad, 0x8e, 0x74, 0xbe, 0xb1, 0x9f, 0xb4}
12:00:21.604 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionOtherFioReqobt
12:00:24.984 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionOtherFioStaking
12:00:25.518:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:25.990:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:26.051:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:26.099:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00d874d0640ca85b000000d42d054dc601
12:00:26.133:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e105374616b652046494f20546f6b656e73
12:00:26.575:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:26.618:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:26.670:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:26.712:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:26.751:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:00:27.127:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f0506416d6f756e74
12:00:27.513:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:27.943:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:00:28.009:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:28.058:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:28.094:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:28.133:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:28.466:seproxyhal: printf: Integrity check for: {0xa8, 0x1e, 0x4e, 0xc5, 0xa9, 0x1e, 0x6b, 0x4d, 0xe2, 0x33, 0x46, 0x1f, 0xfd, 0xbf, 0x3c, 0x84, 0x77, 0x55, 0xcb, 0x1f, 0x64, 0xdd, 0x17, 0xdc, 0xe6, 0x35, 0xb4, 0xb9, 0xe7, 0x7d, 0x27, 0xdc}
12:00:29.777:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:30.265:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:30.306:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:30.350:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00d874d0640ca85b0000754b4193f1d401
12:00:30.392:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e12556e7374616b652046494f20546f6b656e73
12:00:30.750:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:30.794:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:30.853:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:30.889:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:30.957:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:00:31.420:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f0506416d6f756e74
12:00:31.836:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:32.246:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:00:32.297:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:32.351:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:32.395:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:32.479:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:32.789:seproxyhal: printf: Integrity check for: {0x84, 0x95, 0x42, 0x84, 0x3c, 0x8b, 0x00, 0xd8, 0x9c, 0x2c, 0x17, 0xa0, 0x72, 0x66, 0xf9, 0x15, 0x08, 0x0b, 0xc9, 0xf0, 0x48, 0x7c, 0x01, 0x09, 0x15, 0x2e, 0x42, 0x7b, 0x70, 0x82, 0x0d, 0x7a}
12:00:33.961 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionOtherFioStaking
12:00:37.190 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionOtherEosio
12:00:37.578:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:38.084:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:38.161:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:38.191:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:00:38.232:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:00:38.764:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:38.805:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:38.877:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:38.922:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:38.963:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 01
12:00:38.996:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:00:39.417:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:00:39.792:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:39.850:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:40.398:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:40.454:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:40.498:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:40.843:seproxyhal: printf: Integrity check for: {0x72, 0x12, 0x3c, 0xb5, 0x28, 0xc5, 0x67, 0xc4, 0xe3, 0x45, 0x56, 0x1f, 0xa9, 0x74, 0xe3, 0xcc, 0x87, 0x33, 0xbf, 0x9e, 0xe4, 0xc6, 0x37, 0x0b, 0x8f, 0x77, 0x7c, 0xe3, 0xa3, 0xa1, 0x02, 0xa3}
12:00:42.012:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:42.447:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:42.490:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:42.547:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:00:42.589:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:00:42.960:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:43.000:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:43.059:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:43.107:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:43.158:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 02
12:00:43.194:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:00:43.610:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:00:44.002:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:00:44.401:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:44.477:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:44.977:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:45.023:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:45.073:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:45.415:seproxyhal: printf: Integrity check for: {0xbd, 0x92, 0x94, 0x84, 0x09, 0xaa, 0x7b, 0x8e, 0xc0, 0xed, 0x3a, 0x07, 0x81, 0xa3, 0x71, 0x32, 0xec, 0x5d, 0xda, 0x02, 0x54, 0x3f, 0xe7, 0x2c, 0xed, 0xb5, 0xe8, 0xc0, 0xb9, 0x5a, 0xdd, 0x38}
12:00:46.845:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:47.294:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:47.338:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:47.382:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:00:47.424:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:00:47.870:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:47.906:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:47.955:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:47.993:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:48.032:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 03
12:00:48.066:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:00:48.610:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:00:49.000:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:00:49.391:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:00:49.786:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:49.851:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:50.398:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:50.449:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:50.505:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:50.858:seproxyhal: printf: Integrity check for: {0xfd, 0x00, 0x10, 0x47, 0x1a, 0x47, 0xad, 0xd1, 0x5b, 0x01, 0x5d, 0xcf, 0x12, 0xd4, 0xba, 0x20, 0x12, 0x7d, 0xd6, 0x6a, 0x99, 0x37, 0xde, 0x57, 0x79, 0x6a, 0x30, 0x3f, 0xc3, 0x92, 0x45, 0x86}
12:00:53.156:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:53.651:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:53.721:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:53.771:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:00:53.809:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:00:54.170:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:00:54.217:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:54.277:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:00:54.324:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:00:54.356:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 04
12:00:54.415:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:00:54.886:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:00:55.260:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:00:55.720:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:00:56.102:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:00:56.501:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:00:56.561:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:00:57.059:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:00:57.114:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:00:57.173:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:00:57.587:seproxyhal: printf: Integrity check for: {0x4c, 0x3b, 0x0f, 0xe9, 0x89, 0x90, 0xd3, 0x01, 0xac, 0x21, 0x87, 0x6f, 0x36, 0xf1, 0x3c, 0x74, 0xe0, 0xad, 0x9d, 0x6e, 0x2b, 0xb6, 0x5a, 0x22, 0x64, 0x78, 0x04, 0xca, 0x15, 0xa1, 0x8c, 0xfc}
12:00:58.796:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:00:59.298:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:00:59.372:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:00:59.418:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:00:59.465:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:00:59.948:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:00.002:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:00.060:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:00.103:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:00.156:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 05
12:01:00.204:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:00.582:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:00.966:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:01.376:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:01.728:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:02.182:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:02.566:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:02.615:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:02.943:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:02.982:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:03.035:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:03.390:seproxyhal: printf: Integrity check for: {0xbf, 0xb9, 0x78, 0x51, 0x6e, 0x2d, 0x39, 0x0e, 0x60, 0x99, 0x18, 0x16, 0x7b, 0x35, 0xe3, 0xea, 0xa5, 0x6c, 0x85, 0x10, 0x7a, 0x79, 0x31, 0xe3, 0xc3, 0x72, 0x3d, 0x46, 0x4a, 0xb1, 0x40, 0x6a}
12:01:05.595:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:01:06.082:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:01:06.141:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:01:06.184:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:01:06.231:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:01:06.558:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:06.599:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:06.676:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:06.717:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:06.749:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 06
12:01:06.806:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:07.257:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:07.699:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:08.083:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:08.537:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:08.870:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:01:09.296:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:09.686:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:09.753:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:10.247:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:10.292:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:10.371:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:10.756:seproxyhal: printf: Integrity check for: {0x41, 0x5f, 0x45, 0x83, 0x7a, 0xb3, 0xbf, 0x54, 0x4c, 0x6a, 0xa0, 0x99, 0x48, 0xfb, 0x93, 0x9a, 0xa9, 0x9f, 0x4e, 0x60, 0x61, 0x25, 0xea, 0xa3, 0xe3, 0x3e, 0xca, 0x60, 0xde, 0xa9, 0xce, 0x8e}
12:01:11.975:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:01:12.485:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:01:12.534:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:01:12.580:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:01:12.621:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:01:13.036:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:13.071:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:13.116:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:13.172:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:13.206:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 07
12:01:13.240:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:13.770:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:14.270:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:14.656:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:15.041:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:15.475:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:01:15.912:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:01:16.309:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:16.699:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:16.776:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:17.229:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:17.271:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:17.346:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:17.715:seproxyhal: printf: Integrity check for: {0xfd, 0xa3, 0xe5, 0x8e, 0x32, 0x92, 0xb9, 0xa4, 0x6c, 0x17, 0x80, 0x34, 0x87, 0xf8, 0xaf, 0xcd, 0xa8, 0xe5, 0x1e, 0x91, 0xbd, 0x2f, 0x89, 0x8e, 0x1e, 0xe8, 0x30, 0x48, 0xa8, 0x8d, 0xd7, 0xbc}
12:01:19.066:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:01:19.557:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:01:19.605:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:01:19.645:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:01:19.686:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:01:20.053:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:20.090:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:20.138:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:20.195:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:20.224:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 08
12:01:20.261:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:20.783:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:21.206:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:21.652:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:22.043:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:22.460:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:01:22.845:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:01:23.272:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:01:23.696:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:24.124:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:24.189:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:24.658:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:24.734:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:24.782:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:25.162:seproxyhal: printf: Integrity check for: {0x9c, 0x08, 0x4d, 0x07, 0x8a, 0x16, 0x6f, 0x65, 0xca, 0xd8, 0x80, 0x5a, 0x82, 0x6f, 0xe3, 0x28, 0x18, 0x13, 0x88, 0xee, 0xc4, 0xd7, 0xaf, 0x2f, 0xda, 0x1b, 0xe9, 0xa0, 0xf3, 0x74, 0x01, 0x60}
12:01:26.477:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:01:26.983:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:01:27.035:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:01:27.077:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:01:27.117:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:01:27.565:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:27.608:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:27.673:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:27.722:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:27.776:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 09
12:01:27.815:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:28.195:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:28.592:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:28.945:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:29.425:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:29.917:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:01:30.302:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:01:30.699:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:01:31.076:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:01:31.528:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:31.948:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:31.994:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:32.536:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:32.584:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:32.653:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:33.006:seproxyhal: printf: Integrity check for: {0x22, 0x77, 0x67, 0x74, 0x9f, 0x04, 0xfd, 0xb0, 0x1b, 0x4a, 0x9e, 0x87, 0xaa, 0x3c, 0x35, 0xa6, 0xc3, 0xf1, 0xb8, 0x62, 0xb1, 0xd9, 0x12, 0x33, 0x43, 0x55, 0x2d, 0xe8, 0x25, 0x7d, 0x7c, 0xaa}
12:01:34.421:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:01:34.938:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:01:34.979:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:01:35.033:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:01:35.091:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:01:35.439:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:35.476:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:35.542:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:35.599:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:35.658:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0a
12:01:35.694:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:36.061:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:36.459:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:36.868:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:37.254:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:37.665:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:01:38.057:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:01:38.448:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:01:38.854:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:01:39.233:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:01:39.662:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:40.055:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:40.119:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:40.628:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:40.669:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:40.730:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:41.058:seproxyhal: printf: Integrity check for: {0x53, 0x8f, 0xc3, 0xe7, 0xcc, 0x10, 0x26, 0x04, 0x1c, 0xe7, 0x08, 0xfd, 0x9a, 0xf0, 0xf8, 0x8a, 0x06, 0xc4, 0x62, 0x04, 0xa5, 0xd0, 0x7c, 0xfd, 0xd4, 0x99, 0x30, 0xbd, 0x29, 0x98, 0x59, 0x8e}
12:01:42.149:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:01:42.592:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:01:42.644:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:01:42.680:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:01:42.720:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:01:43.155:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:43.193:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:43.244:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:43.293:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:43.340:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0b
12:01:43.392:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:43.880:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:44.272:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:44.661:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:45.115:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:45.516:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:01:45.908:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:01:46.366:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:01:46.770:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:01:47.162:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:01:47.543:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:01:47.964:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:48.341:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:48.388:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:48.921:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:48.959:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:49.017:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:49.321:seproxyhal: printf: Integrity check for: {0x23, 0xc9, 0xce, 0x25, 0xf6, 0x0a, 0xd3, 0x61, 0x65, 0x42, 0xcd, 0x86, 0xb6, 0x76, 0x73, 0x47, 0x7f, 0xf2, 0x14, 0x45, 0x2b, 0x01, 0x66, 0x96, 0x35, 0xed, 0x82, 0xf7, 0x1a, 0xf1, 0x5d, 0x30}
12:01:51.487:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:01:51.963:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:01:52.005:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:01:52.052:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:01:52.091:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:01:52.456:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:01:52.493:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:52.549:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:01:52.591:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:01:52.630:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0c
12:01:52.672:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:01:53.191:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:01:53.590:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:01:53.960:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:01:54.380:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:01:54.744:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:01:55.156:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:01:55.547:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:01:55.946:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:01:56.324:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:01:56.716:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:01:57.105:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:01:57.510:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:01:57.904:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:01:57.947:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:01:58.300:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:01:58.342:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:01:58.391:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:01:58.799:seproxyhal: printf: Integrity check for: {0xac, 0x34, 0x97, 0xb2, 0xd8, 0xeb, 0x94, 0xd3, 0x22, 0x46, 0x08, 0x2e, 0x3f, 0x28, 0x09, 0xb3, 0x40, 0x1a, 0xf0, 0x8f, 0x7d, 0x30, 0x1a, 0x83, 0xd7, 0x7b, 0xbc, 0x13, 0x7c, 0xa2, 0xde, 0x5c}
12:02:00.288:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:02:00.761:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:02:00.811:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:02:00.869:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:02:00.910:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:02:01.265:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:02:01.302:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:01.352:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:02:01.402:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:02:01.455:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0d
12:02:01.503:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:02:01.978:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:02:02.341:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:02:02.803:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:02:03.265:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:02:03.695:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:02:04.093:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:02:04.477:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:02:04.884:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:02:05.272:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:02:05.665:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:02:06.051:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:02:06.443:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:02:06.839:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:02:07.247:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:07.298:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:02:07.801:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:02:07.842:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:02:07.891:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:02:08.268:seproxyhal: printf: Integrity check for: {0x92, 0x80, 0x45, 0xf0, 0x68, 0xab, 0x62, 0x83, 0xfd, 0x9b, 0x55, 0xaf, 0x83, 0xaf, 0x5f, 0x9f, 0x8b, 0x92, 0x4c, 0xb1, 0xb6, 0x2d, 0x12, 0x1a, 0xe9, 0x46, 0xa0, 0x0f, 0x0f, 0xd5, 0x4c, 0x82}
12:02:09.623:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:02:10.109:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:02:10.170:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:02:10.211:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:02:10.267:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:02:10.624:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:02:10.666:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:10.720:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:02:10.785:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:02:10.840:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0e
12:02:10.888:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:02:11.263:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:02:11.641:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:02:12.038:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:02:12.515:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:02:12.900:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:02:13.327:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:02:13.713:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:02:14.103:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:02:14.498:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:02:14.881:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:02:15.287:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:02:15.672:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:02:16.151:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:02:16.518:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:02:16.864:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:16.928:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:02:17.278:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:02:17.322:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:02:17.375:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:02:17.708:seproxyhal: printf: Integrity check for: {0x54, 0xa0, 0xde, 0x88, 0x10, 0xbd, 0x6f, 0x67, 0x14, 0xfc, 0xd1, 0x0d, 0x93, 0xb9, 0xe7, 0x07, 0x28, 0x14, 0x2d, 0xab, 0x50, 0x5c, 0x12, 0x83, 0xdc, 0x87, 0xb5, 0x52, 0x6a, 0x02, 0xf9, 0x61}
12:02:18.804:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:02:19.300:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:02:19.339:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:02:19.380:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:02:19.445:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:02:19.808:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:02:19.850:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:19.903:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:02:19.955:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:02:19.989:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0f
12:02:20.032:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:02:20.562:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:02:20.929:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:02:21.409:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:02:21.784:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:02:22.190:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:02:22.609:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:02:23.041:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:02:23.435:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:02:23.827:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:02:24.230:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:02:24.620:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:02:25.061:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:02:25.446:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:02:25.821:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:02:26.303:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:02:26.683:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:26.746:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:02:27.254:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:02:27.292:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:02:27.341:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:02:27.673:seproxyhal: printf: Integrity check for: {0xf5, 0xd6, 0xf2, 0x37, 0xb4, 0x66, 0x56, 0xe3, 0xca, 0xba, 0xac, 0x01, 0x50, 0x4c, 0x97, 0xa6, 0x2b, 0xb7, 0x14, 0x45, 0xb6, 0x54, 0x7c, 0x18, 0x29, 0xb7, 0xde, 0x4f, 0xf3, 0xae, 0xfd, 0x2}
12:02:28.792:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:02:29.222:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:02:29.284:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:02:29.325:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:02:29.364:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:02:29.753:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:02:29.805:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:29.857:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:02:29.907:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:02:29.940:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 10
12:02:29.979:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:02:30.488:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:02:30.942:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:02:31.352:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:02:31.729:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:02:32.157:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:02:32.557:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:02:32.929:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:02:33.321:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:02:33.725:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:02:34.101:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:02:34.514:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:02:34.964:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:02:35.427:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:02:35.842:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:02:36.349:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:02:36.730:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:02:37.119:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:37.164:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:02:37.527:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:02:37.567:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:02:37.623:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:02:38.056:seproxyhal: printf: Integrity check for: {0x81, 0x6f, 0x57, 0xd9, 0x7d, 0x97, 0x3f, 0xc6, 0x30, 0x61, 0x79, 0x5b, 0x26, 0x2d, 0x57, 0x22, 0xe8, 0xe7, 0xdc, 0x8d, 0xbf, 0xb2, 0xab, 0x51, 0x15, 0x4b, 0x7b, 0x57, 0x52, 0x70, 0xdc, 0x2d}
12:02:39.477:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:02:39.900:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:02:39.978:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:02:40.009:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:02:40.049:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:02:40.382:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:02:40.427:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:40.487:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:02:40.533:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:02:40.583:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 11
12:02:40.623:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:02:41.018:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:02:41.428:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:02:41.775:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:02:42.213:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:02:42.605:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:02:42.931:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:02:43.426:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:02:43.826:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:02:44.257:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:02:44.645:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:02:45.028:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:02:45.411:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:02:45.813:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:02:46.180:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:02:46.591:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:02:46.958:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:02:47.367:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:02:47.750:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:47.795:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:02:48.122:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:02:48.176:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:02:48.256:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:02:48.532:seproxyhal: printf: Integrity check for: {0xa9, 0xae, 0x65, 0x7f, 0x2c, 0x82, 0x95, 0x2b, 0xab, 0x45, 0x31, 0x85, 0x43, 0xe4, 0x12, 0x59, 0x45, 0x4e, 0x2c, 0x10, 0x9c, 0x13, 0xe6, 0xbe, 0x2a, 0x1e, 0x97, 0x0a, 0xce, 0xfa, 0xc6, 0x13}
12:02:50.172:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:02:50.605:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:02:50.652:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:02:50.686:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:02:50.752:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:02:51.211:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:02:51.270:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:51.340:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:02:51.380:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:02:51.436:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 12
12:02:51.484:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:02:51.845:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:02:52.247:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:02:52.636:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:02:53.033:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:02:53.437:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:02:53.843:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:02:54.200:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:02:54.679:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:02:55.071:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:02:55.467:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:02:55.840:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:02:56.260:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:02:56.647:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:02:57.033:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:02:57.422:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:02:57.844:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:02:58.259:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:02:58.640:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:02:59.053:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:02:59.117:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:02:59.619:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:02:59.669:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:02:59.721:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:03:00.028:seproxyhal: printf: Integrity check for: {0x0f, 0x32, 0x00, 0x3e, 0xa4, 0x48, 0xc1, 0xdf, 0x21, 0xe8, 0xf4, 0xec, 0x4e, 0xae, 0x7a, 0x68, 0x36, 0x68, 0x0a, 0x20, 0xb5, 0xa0, 0xd5, 0x2c, 0xec, 0x26, 0x2c, 0x95, 0x04, 0x50, 0xf9, 0x7}
12:03:01.507:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:03:01.923:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:03:01.968:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:03:02.031:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:03:02.077:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:03:02.410:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:03:02.453:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:02.495:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:03:02.545:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:03:02.590:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 13
12:03:02.631:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:03:03.146:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:03:03.532:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:03:04.013:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:03:04.398:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:03:04.794:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:03:05.152:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:03:05.558:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:03:06.020:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:03:06.401:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:03:06.793:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:03:07.178:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:03:07.658:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:03:08.055:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:03:08.441:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:03:08.836:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:03:09.205:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:03:09.677:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:03:10.060:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:03:10.480:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:03:10.867:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:10.919:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:03:11.448:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:03:11.490:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:03:11.549:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:03:11.925:seproxyhal: printf: Integrity check for: {0x5a, 0x28, 0xc1, 0x55, 0xfe, 0x77, 0x53, 0x06, 0xe7, 0x97, 0xcd, 0x1f, 0x65, 0xe5, 0xbe, 0xbe, 0x6a, 0x49, 0xdd, 0x0d, 0xce, 0x10, 0x04, 0x10, 0xf2, 0xcb, 0xe0, 0xad, 0xa4, 0xd7, 0x0d, 0x66}
12:03:13.199:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:03:13.668:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:03:13.708:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:03:13.759:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:03:13.799:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:03:14.149:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:03:14.197:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:14.252:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:03:14.301:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:03:14.353:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 14
12:03:14.391:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:03:14.794:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:03:15.172:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:03:15.621:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:03:16.001:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:03:16.398:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:03:16.832:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:03:17.210:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:03:17.577:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:03:18.013:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:03:18.378:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:03:18.829:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:03:19.233:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:03:19.633:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:03:19.950:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:03:20.335:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:03:20.718:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:03:21.107:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:03:21.572:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:03:21.956:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:03:22.339:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:03:22.721:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:22.766:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:03:23.105:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:03:23.161:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:03:23.232:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:03:23.582:seproxyhal: printf: Integrity check for: {0x89, 0x16, 0x45, 0xa3, 0xad, 0x26, 0xe6, 0xdc, 0xc6, 0xb9, 0x44, 0xb3, 0x74, 0x7c, 0x76, 0xe7, 0x0e, 0x56, 0xb8, 0x39, 0xe5, 0x75, 0xe5, 0x48, 0x23, 0x32, 0x93, 0xb2, 0x7c, 0xbf, 0x44, 0xad}
12:03:24.887:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:03:25.343:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:03:25.406:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:03:25.447:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:03:25.488:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:03:25.939:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:03:25.977:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:26.030:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:03:26.073:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:03:26.107:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 15
12:03:26.150:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:03:26.566:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:03:26.985:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:03:27.347:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:03:27.781:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:03:28.191:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:03:28.526:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:03:29.029:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:03:29.420:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:03:29.806:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:03:30.182:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:03:30.586:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:03:30.961:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:03:31.370:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:03:31.771:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:03:32.171:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:03:32.532:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:03:33.014:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:03:33.404:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:03:33.791:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:03:34.177:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:03:34.573:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:03:34.978:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:35.044:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:03:35.525:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:03:35.577:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:03:35.628:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:03:35.961:seproxyhal: printf: Integrity check for: {0x0c, 0xf2, 0x4f, 0x0e, 0x34, 0xeb, 0x55, 0xae, 0xa2, 0x60, 0x55, 0x46, 0xa3, 0x4e, 0x48, 0x0d, 0xb8, 0x34, 0x58, 0x2a, 0x80, 0x62, 0xc3, 0x07, 0x65, 0x76, 0x65, 0x34, 0xe6, 0xe9, 0x45, 0x69}
12:03:37.200:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:03:37.671:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:03:37.733:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:03:37.792:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:03:37.840:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:03:38.211:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:03:38.252:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:38.304:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:03:38.346:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:03:38.378:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 16
12:03:38.437:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:03:38.899:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:03:39.301:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:03:39.686:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:03:40.059:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:03:40.465:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:03:40.868:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:03:41.275:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:03:41.638:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:03:42.093:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:03:42.482:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:03:42.869:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:03:43.281:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:03:43.688:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:03:44.123:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:03:44.520:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:03:44.921:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:03:45.308:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:03:45.725:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:03:46.122:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:03:46.532:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:03:46.927:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:03:47.301:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:03:47.686:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:47.734:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:03:48.252:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:03:48.299:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:03:48.358:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:03:48.757:seproxyhal: printf: Integrity check for: {0x80, 0x4e, 0x3b, 0x2d, 0xea, 0x0b, 0x2c, 0x7b, 0x06, 0xfb, 0x0c, 0xb5, 0x63, 0xfc, 0x66, 0xf1, 0x0c, 0x95, 0xd0, 0x0e, 0x67, 0x65, 0xa8, 0x98, 0xa3, 0xa8, 0xe0, 0x1e, 0xeb, 0x5e, 0x65, 0x3c}
12:03:50.091:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:03:50.561:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:03:50.620:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:03:50.674:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:03:50.716:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:03:51.047:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:03:51.098:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:03:51.154:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:03:51.197:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:03:51.251:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 17
12:03:51.314:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:03:51.796:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:03:52.228:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:03:52.602:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:03:53.018:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:03:53.407:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:03:53.793:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:03:54.228:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:03:54.666:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:03:55.061:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:03:55.450:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:03:55.831:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:03:56.245:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:03:56.682:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:03:57.127:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:03:57.557:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:03:58.033:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:03:58.416:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:03:58.802:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:03:59.210:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:03:59.564:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:04:00.025:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:04:00.488:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:04:00.812:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:04:01.204:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:01.256:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:04:01.608:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:04:01.652:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:04:01.722:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:04:02.103:seproxyhal: printf: Integrity check for: {0xa2, 0x12, 0x84, 0xf7, 0xd7, 0x4e, 0x24, 0x3b, 0xbd, 0x7c, 0x61, 0x03, 0xbe, 0x8b, 0xeb, 0xeb, 0xde, 0x44, 0x09, 0xf2, 0x5c, 0xd2, 0x08, 0x90, 0x1d, 0x03, 0xf2, 0xaf, 0xa3, 0x22, 0xbc, 0xb1}
12:04:03.307:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:04:03.762:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:04:03.802:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:04:03.841:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:04:03.884:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:04:04.333:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:04:04.374:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:04.454:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:04:04.510:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:04:04.561:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 18
12:04:04.603:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:04:05.143:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:04:05.486:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:04:05.934:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:04:06.333:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:04:06.782:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:04:07.157:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:04:07.547:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:04:07.947:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:04:08.327:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:04:08.701:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:04:09.158:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:04:09.538:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:04:09.932:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:04:10.286:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:04:10.740:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:04:11.117:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:04:11.585:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:04:11.960:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:04:12.357:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:04:12.779:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:04:13.175:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:04:13.575:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:04:13.940:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203234
12:04:14.353:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:04:14.730:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:14.788:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:04:15.306:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:04:15.345:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:04:15.391:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:04:15.773:seproxyhal: printf: Integrity check for: {0x85, 0xd6, 0x13, 0x4e, 0x7e, 0x0c, 0x78, 0x9c, 0x59, 0x8b, 0x42, 0x3d, 0xa8, 0x57, 0x3e, 0x53, 0xb0, 0x82, 0xcb, 0xc9, 0x03, 0x01, 0xe9, 0x62, 0xbd, 0x01, 0x55, 0x73, 0x40, 0xa0, 0xc6, 0xd9}
12:04:17.045:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:04:17.536:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:04:17.582:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:04:17.634:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:04:17.703:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:04:18.223:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:04:18.265:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:18.325:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:04:18.372:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:04:18.408:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 19
12:04:18.445:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:04:18.928:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:04:19.371:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:04:19.857:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:04:20.241:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:04:20.608:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:04:21.094:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:04:21.495:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:04:21.857:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:04:22.302:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:04:22.684:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:04:23.118:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:04:23.493:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:04:23.975:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:04:24.368:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:04:24.758:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:04:25.140:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:04:25.484:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:04:25.893:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:04:26.274:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:04:26.707:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:04:27.122:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:04:27.495:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:04:27.924:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203234
12:04:28.303:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203235
12:04:28.710:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:04:29.090:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:29.150:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:04:29.654:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:04:29.703:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:04:29.766:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:04:30.101:seproxyhal: printf: Integrity check for: {0xaf, 0xca, 0xde, 0x50, 0xca, 0xf1, 0x6f, 0x6c, 0x6e, 0x0e, 0xca, 0x9b, 0xda, 0x54, 0x7d, 0x22, 0xa4, 0x04, 0x32, 0x17, 0x98, 0x63, 0x24, 0x62, 0x37, 0xe4, 0x09, 0x7d, 0x02, 0x15, 0x48, 0xed}
12:04:31.316:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:04:31.779:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:04:31.857:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:04:31.889:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:04:31.941:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:04:32.462:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:04:32.502:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:32.564:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:04:32.608:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:04:32.646:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 1a
12:04:32.700:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:04:33.196:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:04:33.675:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:04:34.075:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:04:34.433:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:04:34.828:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:04:35.214:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:04:35.625:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:04:36.011:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:04:36.423:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:04:36.800:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:04:37.263:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:04:37.671:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:04:38.061:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:04:38.463:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:04:38.850:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:04:39.242:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:04:39.633:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:04:40.013:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:04:40.459:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:04:40.856:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:04:41.224:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:04:41.676:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:04:42.064:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203234
12:04:42.454:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203235
12:04:42.856:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203236
12:04:43.235:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:04:43.632:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:43.688:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:04:44.207:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:04:44.244:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:04:44.289:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:04:44.624:seproxyhal: printf: Integrity check for: {0x7c, 0x77, 0x9d, 0x79, 0xd4, 0x5e, 0x49, 0x5a, 0xd4, 0xb9, 0x8d, 0xf6, 0xb9, 0xb3, 0x4b, 0x44, 0x5e, 0xd3, 0x6a, 0x4a, 0x36, 0x9f, 0x1f, 0xd7, 0x1a, 0x5b, 0xec, 0x19, 0x45, 0xd9, 0x6c, 0x39}
12:04:45.972:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:04:46.450:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:04:46.532:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:04:46.578:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:04:46.627:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:04:47.161:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:04:47.219:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:47.273:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:04:47.316:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:04:47.367:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 1b
12:04:47.415:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:04:47.777:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:04:48.177:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:04:48.569:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:04:48.960:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:04:49.329:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:04:49.719:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:04:50.137:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:04:50.465:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:04:50.885:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:04:51.288:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:04:51.650:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:04:52.098:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:04:52.497:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:04:52.887:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:04:53.267:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:04:53.661:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:04:54.062:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:04:54.431:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:04:54.873:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:04:55.241:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:04:55.639:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:04:56.034:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:04:56.487:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203234
12:04:56.878:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203235
12:04:57.276:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203236
12:04:57.647:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203237
12:04:58.052:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:04:58.444:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:04:58.515:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:04:58.982:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:04:59.026:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:04:59.090:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:04:59.440:seproxyhal: printf: Integrity check for: {0x2e, 0x75, 0xa8, 0x74, 0x8b, 0xcf, 0xdd, 0x43, 0x2d, 0xb2, 0x58, 0x1a, 0x20, 0xc1, 0x06, 0xcd, 0x76, 0x6a, 0x55, 0x6d, 0xac, 0x29, 0x33, 0x62, 0x3e, 0x3f, 0x72, 0xf4, 0xaf, 0xf2, 0x1c, 0x20}
12:05:00.680:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:05:01.186:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:05:01.251:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:05:01.287:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:05:01.327:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:05:01.634:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:05:01.683:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:01.755:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:05:01.817:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:05:01.864:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 1c
12:05:01.914:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:05:02.246:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:05:02.665:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:05:03.149:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:05:03.580:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:05:03.966:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:05:04.342:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:05:04.713:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:05:05.187:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:05:05.559:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:05:06.002:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:05:06.398:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:05:06.756:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:05:07.248:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:05:07.703:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:05:08.090:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:05:08.496:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:05:08.875:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:05:09.289:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:05:09.682:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:05:10.051:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:05:10.538:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:05:10.915:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:05:11.344:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203234
12:05:11.787:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203235
12:05:12.159:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203236
12:05:12.604:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203237
12:05:13.002:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203238
12:05:13.370:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:05:13.758:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:13.813:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:05:14.132:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:05:14.175:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:05:14.246:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:05:14.522:seproxyhal: printf: Integrity check for: {0x3a, 0xb8, 0xac, 0xce, 0x82, 0x3b, 0x31, 0xff, 0xf5, 0x4f, 0x18, 0x95, 0x19, 0x82, 0xed, 0xec, 0x82, 0x76, 0xde, 0x4a, 0x91, 0x4c, 0x97, 0xc8, 0x18, 0xc4, 0xaa, 0x90, 0x65, 0xae, 0x99, 0xc1}
12:05:16.177:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:05:16.635:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:05:16.678:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:05:16.728:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:05:16.781:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:05:17.163:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:05:17.204:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:17.259:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:05:17.323:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:05:17.376:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 1d
12:05:17.419:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:05:17.785:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:05:18.150:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:05:18.602:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:05:19.012:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:05:19.474:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:05:19.839:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:05:20.286:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:05:20.689:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:05:21.073:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:05:21.456:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:05:21.827:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:05:22.305:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:05:22.690:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:05:23.079:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:05:23.516:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:05:23.943:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:05:24.324:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:05:24.776:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:05:25.184:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:05:25.568:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:05:25.962:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:05:26.360:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:05:26.767:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203234
12:05:27.151:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203235
12:05:27.549:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203236
12:05:27.903:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203237
12:05:28.385:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203238
12:05:28.767:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203239
12:05:29.172:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:05:29.558:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:29.619:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:05:30.095:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:05:30.151:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:05:30.219:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:05:30.549:seproxyhal: printf: Integrity check for: {0x2c, 0x03, 0x66, 0x3b, 0xa4, 0xa8, 0x16, 0xe1, 0xd5, 0x33, 0xed, 0xc9, 0x53, 0xe4, 0xe0, 0xb2, 0xb5, 0xf1, 0x9f, 0xfa, 0x48, 0x61, 0x62, 0xdc, 0xd2, 0x20, 0x6e, 0xc9, 0x46, 0x8c, 0xe2, 0xcb}
12:05:31.819:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:05:32.246:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:05:32.320:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:05:32.356:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30557015d289deaa32dd01
12:05:32.415:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e1c566f746520666f722046494f20426c6f636b2070726f647563657273
12:05:32.758:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:05:32.798:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:32.854:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:05:32.913:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:05:32.953:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 1e
12:05:33.008:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722031
12:05:33.480:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722032
12:05:33.869:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722033
12:05:34.280:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722034
12:05:34.655:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722035
12:05:35.057:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722036
12:05:35.453:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722037
12:05:35.823:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722038
12:05:36.307:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a50726f64756365722039
12:05:36.667:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203130
12:05:37.102:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203131
12:05:37.460:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203132
12:05:37.933:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203133
12:05:38.342:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203134
12:05:38.711:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203135
12:05:39.158:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203136
12:05:39.542:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203137
12:05:39.941:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203138
12:05:40.329:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203139
12:05:40.737:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203230
12:05:41.141:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203231
12:05:41.538:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203232
12:05:41.915:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203233
12:05:42.306:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203234
12:05:42.691:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203235
12:05:43.075:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203236
12:05:43.539:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203237
12:05:43.943:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203238
12:05:44.333:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203239
12:05:44.758:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050b50726f6475636572203330
12:05:45.171:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:05:45.543:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:45.589:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:05:45.938:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:05:45.999:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:05:46.047:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:05:46.352:seproxyhal: printf: Integrity check for: {0x4a, 0xde, 0x67, 0x61, 0x5f, 0xa6, 0x74, 0x60, 0xa0, 0x70, 0x9b, 0x9e, 0x81, 0x0f, 0x54, 0x76, 0xe8, 0x6a, 0xed, 0x5b, 0xaa, 0xbc, 0x04, 0x96, 0xc1, 0x5d, 0xeb, 0x28, 0xf5, 0x7c, 0xa5, 0x25}
12:05:47.506:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:05:47.973:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:05:48.052:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:05:48.086:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000000ea30550000f09ddeaa32dd01
12:05:48.121:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0b50726f787920766f746573
12:05:48.475:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:05:48.527:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:48.588:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:05:48.626:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:05:48.684:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050550726f7879
12:05:49.069:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040204000000000000004100000000000000050a46494f2048616e646c65
12:05:49.487:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:49.550:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:05:50.005:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:05:50.058:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:05:50.110:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:05:50.473:seproxyhal: printf: Integrity check for: {0xf8, 0x4d, 0xac, 0xa3, 0xb0, 0x93, 0xa7, 0x32, 0x47, 0x21, 0x4c, 0x7e, 0xf1, 0xfb, 0x99, 0x0a, 0xb5, 0x4f, 0xf0, 0x6b, 0x9d, 0x3b, 0x69, 0xac, 0x73, 0xd9, 0x91, 0xf9, 0xdf, 0x79, 0x54, 0x4c}
12:05:51.495 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionOtherEosio
12:05:55.279 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv testStart() // snapshots/signTransactionOtherFioOracle
12:05:55.886:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:05:56.332:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:05:56.373:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:05:56.407:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00808ac85c0aa85b00c07446d254cde501
12:05:56.460:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0f577261702046494f20446f6d61696e
12:05:56.903:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:05:56.951:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:57.000:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:05:57.055:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:05:57.100:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000003f00000000000000050a46494f20446f6d61696e
12:05:57.588:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
12:05:58.072:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050e5075626c69632041646472657373
12:05:58.439:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f050e4d6178206f7261636c6520666565
12:05:58.830:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:05:59.262:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:05:59.313:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:05:59.362:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:05:59.402:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:05:59.465:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:05:59.847:seproxyhal: printf: Integrity check for: {0x15, 0x20, 0xa0, 0x1b, 0x8c, 0x14, 0xc1, 0x46, 0x2c, 0xe2, 0xcb, 0x55, 0x20, 0x7c, 0xef, 0xba, 0x6d, 0x77, 0x56, 0x5f, 0xec, 0xe1, 0xbf, 0xe9, 0x0a, 0x60, 0xf9, 0xa2, 0xe1, 0x2d, 0x33, 0xf8}
12:06:01.076:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 01. p2: 00, constdata: 
12:06:01.574:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 01020a000000000000000a000000000000000200
12:06:01.624:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 0000000001
12:06:01.673:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 00808ac85c0aa85b00009e0ad25ccde501
12:06:01.708:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 03. p2: 00, constdata: 06416374696f6e0b5772617020546f6b656e73
12:06:02.126:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 07. p2: 01, constdata: 
12:06:02.170:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:06:02.221:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000000200
12:06:02.261:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 05. p2: 00, constdata: 17030000000000000000ffffffff00000000
12:06:02.315:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f0506416d6f756e74
12:06:02.678:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040202000000000000000b00000000000000050a436861696e20636f6465
12:06:03.078:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 040201000000000000000400000001000000050e5075626c69632041646472657373
12:06:03.473:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f050e4d6178206f7261636c6520666565
12:06:03.801:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 10030000000000000000ffffffffffffff7f05074d617820666565
12:06:04.188:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0402010000000000000004000000010000000200
12:06:04.249:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 04. p2: 00, constdata: 0102080000000000000008000000000000001200
12:06:04.292:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 06. p2: 00, constdata: 
12:06:04.327:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 02. p2: 00, constdata: 000000000000000000000000000000000000000000000000000000000000000000
12:06:04.369:seproxyhal: printf: [integrityCheckProcessInstruction:322] p1: 10. p2: 00, constdata: 
12:06:04.765:seproxyhal: printf: Integrity check for: {0x97, 0xb8, 0xd1, 0xc4, 0x89, 0x18, 0x9b, 0xbc, 0xcb, 0xc6, 0xb1, 0x8e, 0x54, 0x0c, 0xba, 0x73, 0x37, 0xd2, 0xe3, 0x8f, 0x04, 0x3e, 0x98, 0xad, 0xb9, 0x7e, 0x6d, 0xba, 0xaa, 0xae, 0xef, 0xa0}
12:06:06.421 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ testEnd()   // snapshots/signTransactionOtherFioOracle

