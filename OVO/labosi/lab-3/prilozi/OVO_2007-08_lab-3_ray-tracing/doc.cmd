pushd src
if exist compile-list.txt del compile-list.txt
for %%a in ( raytracing\* ) do echo %%a >> compile-list.txt
echo Generating javadoc
javadoc -d ../doc -sourcepath . @compile-list.txt
popd
