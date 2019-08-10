/*
 * Copyright (c) 2013-2019 Snowflake Computing
 */
#include "StringConverter.hpp"

namespace sf
{
Logger StringConverter::logger("snowflake.connector.StringConverter");

StringConverter::StringConverter(std::shared_ptr<arrow::Array> array)
: m_array(std::dynamic_pointer_cast<arrow::StringArray>(array))
{
}

PyObject* StringConverter::toPyObject(int64_t rowIndex)
{
  if (m_array->IsValid(rowIndex))
  {
    arrow::util::string_view sv = m_array->GetView(rowIndex);
    return PyUnicode_FromStringAndSize(sv.data(), sv.size());
  }
  else
  {
    Py_RETURN_NONE;
  }
}

}  // namespace sf
