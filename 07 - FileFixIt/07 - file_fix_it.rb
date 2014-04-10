#
#  file_fix_it.rb
#  FileFixIt
#
#  Created by Muhammad Hussein Nasrollahpour on 4/10/14.
#  Copyright (c) 2014 Chocolate. All rights reserved.
#

input = File.open("/Users/muhammad/Desktop/in.txt", "r")
output = File.open("/Users/muhammad/Desktop/out.txt", "w")

t = Integer input.first

_case = 1

input.each_line do |line|
  values = []
  line.split(" ").each do |value|
    values.push Integer value
  end

  n = values[0]
  m = values[1]

  existent_paths = []
  for counter in 0...n
    existent_paths.push input.first
  end

  new_paths = []
  for counter in 0...m
    new_paths.push input.first
  end

  if existent_paths.empty?
    dirs = []
    new_paths.each do |path|
      path.split("/").each do |dir|
        dirs.push dir
      end
    end

    created_dirs = []
    dirs.each do |dir|
      if !(created_dirs.include? dir) && dir != " "
        created_dirs.push dir
      end
    end

    created_dirs.delete_at(0)

    result = "Case ##{_case}: #{created_dirs.count}\n"

    output.write result

    _case += 1
  else
    existent_dirs = []
    existent_paths.each do |ex_path|
      ex_path.split("/").each do |dir|
        existent_dirs.push dir
      end
    end

    for idx in 0...existent_dirs.count
      if "" == existent_dirs[idx]
        existent_dirs.delete_at(idx)
      end
    end

    new_dirs = []
    new_paths.each do |nw_path|
      nw_path.split("/").each do |dir|
        new_dirs.push dir
      end
    end

    for idx in 0...new_dirs.count
      if "" == new_dirs[idx]
        new_dirs.delete_at(idx)
      end
    end

    # FIXME
    created_dirs = []
    existent_dirs.each_index do |e_idx|
      new_dirs.each_index do |n_idx|
        if existent_dirs[e_idx] != new_dirs[n_idx]
          created_dirs.push new_dirs[n_idx]
        end
      end
    end
    # FIXME

    created_dirs.delete_at(0)

    result = "Case ##{_case}: #{created_dirs.count}\n"

    output.write result

    _case += 1
  end
end
