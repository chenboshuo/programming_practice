def is_ipv6(ip):
  nums = ip.split(':')
  if len(nums) != 8 :# more groups or :: cases
      return "Neither"
  for d in nums:
    try:
      d = int(d,base=16)
      assert 0 <= d <= int('ffff',base=16)
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
        if '-' in IP:
          return "Neither"
        if ':' in IP:
          return is_ipv6(IP)
        return is_ipv4(IP)

# Input:
# "2001:0db8:85a3:00000:0:8A2E:0370:7334"
# Output:
# "IPv6"
# Expected:
# "Neither"
