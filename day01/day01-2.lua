local number = io.read("*a")
local n = string.len(number)

local captcha_sum = 0
local half_len = n / 2

for i = 1, n do
  local next_ind = (i + half_len - 1) % n + 1

  if next_ind == 0 then
    next_ind = 1
  end

  local curr_char = number:sub(i, i)
  local next_char = number:sub(next_ind, next_ind)

  if curr_char == next_char then
    local as_int = string.byte(curr_char) -string.byte("0")
    captcha_sum = captcha_sum + as_int
  end
end

print(captcha_sum)
