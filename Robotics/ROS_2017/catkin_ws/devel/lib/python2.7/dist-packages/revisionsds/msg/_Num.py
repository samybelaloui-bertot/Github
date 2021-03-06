# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from revisionsds/Num.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Num(genpy.Message):
  _md5sum = "573e6d965152a0f87d8b826f7a5df63c"
  _type = "revisionsds/Num"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int64 valint
int64 valinttwo
float32 valfloat

"""
  __slots__ = ['valint','valinttwo','valfloat']
  _slot_types = ['int64','int64','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       valint,valinttwo,valfloat

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Num, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.valint is None:
        self.valint = 0
      if self.valinttwo is None:
        self.valinttwo = 0
      if self.valfloat is None:
        self.valfloat = 0.
    else:
      self.valint = 0
      self.valinttwo = 0
      self.valfloat = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2qf.pack(_x.valint, _x.valinttwo, _x.valfloat))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 20
      (_x.valint, _x.valinttwo, _x.valfloat,) = _struct_2qf.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2qf.pack(_x.valint, _x.valinttwo, _x.valfloat))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 20
      (_x.valint, _x.valinttwo, _x.valfloat,) = _struct_2qf.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2qf = struct.Struct("<2qf")
