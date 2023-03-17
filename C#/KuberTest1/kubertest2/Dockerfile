#See https://aka.ms/customizecontainer to learn how to customize your debug container and how Visual Studio uses this Dockerfile to build your images for faster debugging.

FROM mcr.microsoft.com/dotnet/aspnet:7.0 AS base
WORKDIR /app
EXPOSE 80
EXPOSE 443

FROM mcr.microsoft.com/dotnet/sdk:7.0 AS build
WORKDIR /src
COPY ["kubertest2.csproj", "kubertest2/"]
RUN dotnet restore "kubertest2/kubertest2.csproj"
WORKDIR "/src/kubertest2"
COPY . .
RUN dotnet build "kubertest2.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "kubertest2.csproj" -c Release -o /app/publish /p:UseAppHost=false

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "kubertest2.dll"]