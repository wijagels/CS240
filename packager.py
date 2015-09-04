#! /usr/bin/env python3
"""
VERSION 1.0

This script was written by William Jagels because he was upset about
the required naming conventions for CS 240.  This script makes assumptions
about your directory structure.  Labs should be in folders named with
the number that they correspond to.  This shouldn't be hard to change
if you want to organize your stuff differently.  Change the __lab_name__
variable to suit your needs.

The script will dump your code into /tmp/ and then run some sed magic
to change file references.  It will prepend __file_prefix__ onto file
names to fit the naming scheme required by the course.  If it compiles
with shortened names, it should also compile with the changed names.
If it doesn't, then you have to do some extra work.  It's not my fault
if you blindly submit the .tar.gz file that's generated and it doesn't
work.  If there's a case where your lab doesn't compile, feel free to
complain to me, because there's probably room to improve this script.

Happy hacking.

Below is the license
====================

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

(In other words, do whatever you want.)
"""

import os
import re
import shutil
import subprocess
import time


def main():
    """
        First step is to establish a working directory.
        I chose /tmp/ because there shouldn't be anything
        important in there.
    """
    print('Make ' + '/tmp/' + __tmp_path__)
    os.mkdir('/tmp/' + __tmp_path__)
    for filename in os.listdir('.'):
        if filename == 'makefile':
            print('Copy makefile')
            shutil.copy(filename, '/tmp/' + __tmp_path__ + '/' + filename)
        if not __regex__.match(filename):
            print('Copy ' + __file_prefix__ + filename)
            shutil.copy(filename, '/tmp/' + __tmp_path__ + '/' +
                        __file_prefix__ + filename)

    """
       Now that files have been copied over, we have to
       fix all the broken references.
       This sed magic should normally work.
    """
    print("Doing sed stuff, please ignore errors about file not found")
    for filename in os.listdir('.'):
        if not __regex__.match(filename):
            os.popen("sed -i -e 's/" + filename + "/" +
                     __file_prefix__ + filename + "/g' /tmp/" +
                     __tmp_path__ + "/*")

    """
        Now that we have all our files named correctly,
        we can compress them
    """
    print('Sleeping 5 seconds to let filesystem settle')
    time.sleep(5)
    print('Now generating tar.gz file in current directory')
    subprocess.call('tar -cvzf ' + __tgz_file__ + ' -C /tmp/ '
                    + __tmp_path__ + '/', shell=True)
    print('Cleaning up the temporary directory...')
    shutil.rmtree('/tmp/' + __tmp_path__)

__file_prefix__ = 'Jagels_William_'
__dir_end__ = 'wjagels1'
__ignore_regex__ = '(?:.*\.o$)|(?:.*\.out$)|(?:^makefile$)|(?:.*\.py$)'
__regex__ = re.compile(__ignore_regex__)
__lab_name__ = 'Lab' + os.path.basename(os.getcwd())
__tmp_path__ = __lab_name__ + __dir_end__
__tgz_file__ = __file_prefix__ + __lab_name__ + '.tar.gz'

main()
