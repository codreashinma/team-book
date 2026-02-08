module ReVIEW
  module LATEXBuilderOverride
    def hr
      puts '\reviewhr'
    end
  end

  class LATEXBuilder
    prepend LATEXBuilderOverride
  end
end
