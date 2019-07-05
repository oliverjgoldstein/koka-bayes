To install and run this library:

<b>To install koka-bayes:</b> <br />
From the root directory of where you downloaded koka-bayes:
1. <code> make install </code> -- this will install koka-bayes into koka.
2. <code> make run </code> -- this will only run the main function and demonstrate example output. <br />

<b>To develop koka-bayes:</b> <br />
From the root of the development directory.
1. <code> make dev </code> -- this will copy all files from the development directory into the koka-bayes module (replacing them in the process) and run the main function. <br />

Detail: The makefile uses only two ~/.bash_profile variables. If constantly changing where you develop from - ensure that these remain in sync.
1. KOKA_GIT which is where you DEVELOP from.
2. KOKA_INSTALL which is the root directory of the koka library.
