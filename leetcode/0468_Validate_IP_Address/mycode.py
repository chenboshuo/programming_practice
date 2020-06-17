def is_ipv6(ip):
  nums = ip.split(':')
  if len(nums) != 8 :# more groups or :: cases
      return "Neither"
  for d in nums:
    try:
      assert len(d) == 4 or d == '0'
      d = int(d,base=16)
    except:
      return "Neither"

  return "IPv6"

def is_ipv4(ip):
  nums = ip.split('.')
  if len(nums) != 4:
    return "Neither"
  for d in nums:
    try:
      assert d[0] != '0' or d == '0'
      d = int(d)
      assert  0 <= d <= 255
    except:
      return "Neither"
  return "IPv4"

class Solution:
    def validIPAddress(self, IP: str) -> str:
        if ':' in IP:
          return is_ipv6(IP)
        return is_ipv4(IP)
