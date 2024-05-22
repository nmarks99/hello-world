-- Returns a new string with all occurances of 
-- a substring 'old' in 'str' replaced with 'new'
function string_replace(str, old, new)
    local result = ""
    local start_index = 1
    while true do
        local found_start, found_end = string.find(str, old, start_index, true)
        if not found_start then
            break
        end
        result = result .. string.sub(str, start_index, found_start - 1) .. new
        start_index = found_end + 1
    end
    result = result .. string.sub(str, start_index)
    return result
end

-- splits a string into a table by a delimeter and returns the table
function string_split(input_str, delimiter)
    local words = {}
    delimiter = delimiter or "%s"  -- Default delimiter is whitespace
    local pattern = string.format("([^%s]+)", delimiter)
    for word in string.gmatch(input_str, pattern) do
        table.insert(words, word)
    end
    return words
end

