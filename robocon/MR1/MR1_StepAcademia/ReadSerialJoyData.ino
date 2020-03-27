bool flag = false;
bool ReadSerialJoyData(String &str, int &X, int &Y)
{
  if (str.lastIndexOf('X') == -1 || str.lastIndexOf('Y') == -1 || str.lastIndexOf('*') == -1)
    return false;
  String val = "";
  int i = 1;
  for (i = 1; str.charAt(i) != 'Y'; i++)
    if (val += str.charAt(i));

  X = val.toInt();
  val = "";
  i++;
  for (; str.charAt(i) != '*'; i++)
    if (val += str.charAt(i));
  Y = val.toInt();
  if (!X || !Y)
    return false;
  str = "";
  return true;
}
