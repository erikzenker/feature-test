defmodule Say do
  def build do
    ""
  end  
  
  def concat(content, new_content) do
    content <> new_content
  end

  def replace(content, pattern, replacement) do
    String.replace(content, pattern, replacement)
  end

  def space(content) do
    concat(content, " ")
  end

  def print(content) do
    IO.puts content
    content
  end  
    
end


Say.build()
    |> Say.concat("hello")
    |> Say.space
    |> Say.concat("world")
    |> Say.print
    |> Say.replace("hello", "hallo")
    |> Say.replace("world", "welt")
    |> Say.print


