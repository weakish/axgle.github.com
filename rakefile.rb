task :default do
	sh "git commit -a -m '.'"
	sh "git push origin master"
end

task :lf do
  Dir["*.htm"].each do |f|
    d=IO.read(f).gsub(/index.htm/,"index.html")
    puts f
    open(f,"w"){|f|f<<d}
  end  
end  

task :pdf do
  puts "adobe reader 920 is good!"
end  

desc "dreamweaver edit ruby"
task :dw do
	puts "http://blog.csdn.net/roso99/archive/2007/06/06/1640865.aspx"
end