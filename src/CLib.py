from ctypes import CDLL
import os
from ctypes import CDLL
from pathlib import Path
from tempfile import NamedTemporaryFile


class CLib(object):
    _tempfile = None
    _lib = None
    import _ctypes
    _libclose = getattr(_ctypes, 'FreeLibrary', getattr(_ctypes, 'dlclose', None))
    functypes = dict()

    def __init__(self, filename=None, functypes=None):
        if functypes != None:
            self.functypes = functypes
        if filename != None:
            self.load(filename)

    def __getattr__(self, name):
        if self._lib == None:
            return None
        return getattr(self._lib, name)

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self._free()

    def __del__(self):
        self._free()

    def _free(self):
        if self._lib != None:
            handle = self._lib._handle
            del self._lib
            if self._libclose != None: self._libclose(handle)
        if self._tempfile != None:
            self._tempfile.close()
            os.remove(self._tempfile.name)

    def load(self, filename):
        self._free()
        self._tempfile = NamedTemporaryFile(delete=False, suffix=".ctypelib")


        libfile = open(filename, 'rb')
        while True:
            b = libfile.read(2048)
            if b:
                self._tempfile.write(b)
            else:
                break
        libfile.close()
        self._tempfile.close()
        self._lib = CDLL(self._tempfile.name)
        for k in self.functypes:
            if hasattr(self._lib, k):
                getattr(self._lib, k).restype = self.functypes[k][0]
                getattr(self._lib, k).argtype = self.functypes[k][1]
