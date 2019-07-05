To install and run this library:

This script uses only two bash_profile variables.
1. KOKA_GIT which is where you DEVELOP from.
2. KOKA_INSTALL which is the root directory of the koka library.  

To install: From the root directory of where you downloaded koka-bayes:
<code> make install </code> -- this will install koka-bayes into koka. <br/>
<code> make run </code> -- this will only run the main function and demonstrate example output. <br />

To develop: From the root of the development directory.
<code> make dev </code> -- this will copy all files from the development directory into the koka-bayes module (replacing them in the process) and run the main function. <br />
